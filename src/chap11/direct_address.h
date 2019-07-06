#ifndef DIRECT_ADDRESS_H
#define DIRECT_ADDRESS_H

typedef struct {
  int key;
} node;

void malloc_error(void *p);
node *generate_node(int k);
node **direct_address_init(int size);
node *direct_address_search(node **table, int k);
void direct_address_insert(node **table, node *x);
void direct_address_delete(node **table, node *x);
node **generate_nodes(int length);
void print_table(node **table, int length);

#endif
