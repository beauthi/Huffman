#ifndef QUEUE_H_
# define QUEUE_H_

# include <string.h>
# include "tree.h"

/*
   This file is made for priority queues implementation.
   Letters are ordered in the queue.
*/

typedef struct queue queue;
struct queue
{
  tree *t;
  size_t size;
};

tree *build_tree(map *letters);

#endif /* QUEUE_H_ */
