#include "queue.h"

static void init_queue_case(queue *q, int i, int j)
{
  q->t[i].is_leaf = q->t[j].is_leaf;
  q->t[i].weight = q->t[j].weight;
  q->t[i].r = q->t[j].r;
  q->t[i].l = q->t[j].l;
  q->t[i].code = NULL;
  q->t[i].let = q->t[j].let;
}

static void queue_add(queue *trees, tree *t)
{
  queue *q = trees;
  size_t i = 0;
  while (i < q->size && q->t[i].weight < t->weight)
    i++;
  q->size += 1;
  q->t = realloc(q->t, sizeof (tree) * q->size);
  for (int j = q->size - 1; j > i; j--)
    init_queue_case(q, j, j - 1);
  q->t[i].is_leaf = t->is_leaf;
  q->t[i].weight = t->weight;
  q->t[i].r = t->r;
  q->t[i].l = t->l;
  q->t[i].code = NULL;
  q->t[i].let = t->let;
}

static tree *queue_pop(queue *trees)
{
  tree *t = malloc(sizeof (tree));
  t->is_leaf = trees->t[0].is_leaf;
  t->weight = trees->t[0].weight;
  t->r = trees->t[0].r;
  t->l = trees->t[0].l;
  t->let = trees->t[0].let;
  t->code = NULL;
  for (size_t i = 0; i < trees->size - 1; i++)
    init_queue_case(trees, i, i + 1);
  trees->size -= 1;
  trees->t = realloc(trees->t, sizeof (tree) * trees->size);
  return t;
}

void disp_tree(tree *t)
{
  if (!t)
    return;
  printf("%c, %d\n", t->let.c, t->weight);
  disp_tree(t->l);
  disp_tree(t->r);
}

tree *build_tree(map *letters)
{
  queue *q = malloc(sizeof (queue));
  q->size = 0;
  q->t = NULL;
  for (size_t i = 0; i < letters->size; i++)
  {
    tree *t = malloc(sizeof (tree));
    t->is_leaf = 1;
    t->weight = letters->vect[i].occ;
    t->r = NULL;
    t->l = NULL;
    t->code = NULL;
    t->let = letters->vect[i];
    queue_add(q, t);
  }
  /* A special letter of occurence -1 is created for all the nodes that just represent weights
     of sub-nodes */
  letter l =
  {
    '!', -1
  };
  while (q->size != 1)
  {
    tree *left = queue_pop(q);
    tree *right = queue_pop(q);
    tree *node = malloc(sizeof (tree));
    node->is_leaf = 0;
    node->weight = left->weight + right->weight;
    node->l = left;
    node->r = right;
    node->let = l;
    node->code = NULL;
    queue_add(q, node);
  }
  return q->t;
}
