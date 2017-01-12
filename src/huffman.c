#include "huffman.h"

static void add_letter(map *letters, char c)
{
  size_t i = 0;
  for (; i < letters->size && c != letters->vect[i].c; i++)
    continue;
  if (i == letters->size)
  {
    letters->size += 1;
    letters->vect = realloc(letters->vect, letters->size * sizeof (letter));
    letter l;
    l.c = c;
    l.occ = 0;
    letters->vect[letters->size - 1] = l;
  }
  letters->vect[i].occ += 1;
}

void fill_letters_occ(map *letters, char *sentence)
{
  for (size_t i = 0; sentence[i]; i++)
    add_letter(letters, sentence[i]);
}
