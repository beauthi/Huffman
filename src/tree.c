#include "tree.h"

static size_t my_strlen(char *sent)
{
  size_t len = 0;
  while (sent[len])
    len++;
  return len;
}

static char *find(tree *t, char c)
{
  if (!t)
    return NULL;
  if (t->let.c == c && t->weight != -1)
    return t->code;
  char *s1 = find(t->l, c);
  if (s1)
    return s1;
  char *s2 = find(t->r, c);
  if (s2)
    return s2;
  return NULL;
}

static char *concat(char *s1, char *s2)
{
  size_t s1_len = my_strlen(s1);
  size_t s2_len = my_strlen(s2);
  char *conc = malloc(sizeof (char) * (s1_len + s2_len + 1));
  for (size_t i = 0; i < my_strlen(s1); i++)
  {
    conc[i] = s1[i];
    conc[i + s1_len] = s2[i];
  }
  conc[s1_len + s2_len] = '\0';
  return conc;
}

void fill_codes(tree *t, char *code)
{
  if (!t)
    return;
  t->code = code;
  fill_codes(t->r, concat(code, "1"));
  fill_codes(t->l, concat(code, "0"));
}

static void assign_letter(letter *l, letter *m)
{
  l->c = m->c;
  l->occ = m->occ;
}

static void insertion_sort(map *letters)
{
  for (size_t i = 1; i < letters->size - 1; i++)
  {
    letter key = letters->vect[i];
    int j = i - 1;
    while (j >= 0 && letters->vect[j].occ < key.occ)
    {
      assign_letter(letters->vect + j + 1, letters->vect + j);
      j--;
    }
    while (j >= 0 && letters->vect[j].c > key.c && letters->vect[j].occ == letters->vect[i].occ)
    {
      assign_letter(letters->vect + j + 1, letters->vect + j);
      j--;
    }
    letters->vect[j + 1] = key;
  }
}

void print_array(map *letters, tree *t)
{
  insertion_sort(letters);
  printf("Char\t|\tFreq\t|\tCode\n");
  for (size_t i = 0; i < letters->size; i++)
  {
    if (letters->vect[i].c == ' ')
      printf("' '");
    else
      printf("%c", letters->vect[i].c);
    printf("\t|\t%d\t|\t%s\n", letters->vect[i].occ, find(t, letters->vect[i].c));
  }
}

void decode(char *sent, tree *t)
{
  fill_codes(t->l, "0");
  fill_codes(t->r, "1");
  char *code = "";
  for (int i = 0; i < my_strlen(sent); i++)
  {
    code = find(t, sent[i]);
    printf("%s", code);
  }
}
