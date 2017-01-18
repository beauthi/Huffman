#include "queue.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage : ./huffman file\n");
    exit(1);
  }
  FILE *f = fopen(argv[1], "r");
  if (!f)
  {
    fprintf(stderr, "%s : No such file or directory\n", argv[1]);
    exit(1);
  }
  map *letters = malloc(sizeof (map));
  letters->size = 0;
  letters->vect = NULL;
  char r[1000];
  while (fgets(r, 1000, f))
  {
    if (strlen(r) < 1000)
      r[strlen(r) - 1] = '\0';
    fill_letters_occ(letters, r);
  }
  tree *t = build_tree(letters);
  fill_codes(t->l, "0");
  fill_codes(t->r, "1");
  printf("\nFirst Threshold\n\n");
  print_array(letters, t);
  free(letters);
  fclose(f);
  return 0;
}
