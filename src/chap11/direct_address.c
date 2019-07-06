#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "direct_address.h"

#define NIL -1

void malloc_error(void *p) {
  if (!p) {
    printf("error: malloc memory failed\n");
    exit(0);
  }
}

node *generate_node(int k) {
  node *n = (node *) malloc(sizeof(node));
  malloc_error(n);
  n->key = k;
  return n;
}

node **direct_address_init(int size) {
  int i;
  node **table = (node **) malloc(size * sizeof(node *));
  malloc_error(table);
  for (i = 0; i < size; i++) {
    node *n = generate_node(NIL);
    table[i] = n;
  }

  return table;
}

node *direct_address_search(node **table, int k) {
  return table[k];
}

void direct_address_insert(node **table, node *x) {
  table[x->key] = x;
}

void direct_address_delete(node **table, node *x) {
  node *n = generate_node(NIL);
  table[x->key] = n;
}

node **generate_nodes(int length) {
  int i;
  node **nodes = (node **) malloc(length * sizeof(node *));
  malloc_error(nodes);
  for (i = 0; i < length; i++) {
    nodes[i] = generate_node(i);
  }

  return nodes;
}

void print_table(node **table, int length) {
  int i;
  for (i = 0; i < length; i++) {
    printf("%d ", table[i]->key);
  }
  printf("\n");
}

int main() {
  int i = 0, n = 10;
  node **table;
  node **nodes = generate_nodes(n);

  table= direct_address_init(n);
  print_table(table, n);
  for (i = 0; i < n; i++) {
    direct_address_insert(table, nodes[i]);
    print_table(table, n);
  }
  for (i = 0; i < n; i++) {
    direct_address_delete(table, nodes[i]);
    print_table(table, n);
  }

  return 0;
}
