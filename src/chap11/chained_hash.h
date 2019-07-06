#ifndef CHAINED_HASH_H
#define CHAINED_HASH_H

typedef struct node_struct node;
struct node_struct {
  int key;
  node *next;
  node *prev;
};

typedef struct {
  node *nil;
} sen_list;

#endif
