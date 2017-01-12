#ifndef _HUFFMAN_H
# define _HUFFMAN_H
# include <stdio.h>
# include <stdlib.h>

typedef struct letter letter;
struct letter
{
  char c;
  int occ;
};

typedef struct map map;
struct map
{
  letter *vect;
  size_t size;
};

void fill_letters_occ(map *letters, char *sentence);

#endif	/* _HUFFMAN_H */
