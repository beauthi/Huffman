#ifndef _TREE_H
# define _TREE_H

# include "huffman.h"

typedef struct tree tree;
struct tree
{
  int is_leaf;
  int weight;
  tree *r;
  tree *l;
  char *code;
  letter let;
};

void decode(char *sent, tree *t);
void print_array(map *letters, tree *t);
void fill_codes(tree *t, char *code);

#endif /* _TREE_H */
