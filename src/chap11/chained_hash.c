#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "chained_hash.h"

#define NIL -1

void malloc_error(void *p) {
  if (!p) {
    printf("error: malloc memory failed\n");
    exit(0);
  }
}

void init_list(sen_list *l) {
  node *x = (node *) malloc(sizeof(node));
  malloc_error(x);
  l->nil = x;
  l->nil->key = NIL;
  l->nil->next = l->nil;
  l->nil->prev = l->nil;
}

void chained_hash_init(sen_list ** table, int size) {
  int i;
  for (i = 0; i < size; i++) {
    sen_list *l = (sen_list *) malloc(sizeof(sen_list));
    malloc_error(l);
    init_list(l);
    table[i] = l;
  }
}

node *list_search(sen_list *l, int element) {
  node *x = l->nil->next;
  while (x != l->nil && x->key != element)
    x = x->next;
  return x;
}

void list_insert(sen_list *l, node *x) {
  x->next = l->nil->next;
  l->nil->next->prev = x;
  x->prev = l->nil;
  l->nil->next = x;
}

void list_delete(sen_list *l, int k) {
  node *x = list_search(l, k);
  if (x != NULL) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
  }
}

int hash(int size, int k) {
  return k % size;
}

node *chained_hash_search(sen_list **table, int k, int size) {
  int r = hash(size, k);
  if (r >= 0)
    return list_search(table[r], k);
  else
    return NULL;
}

void chained_hash_insert(sen_list **table, node *x, int size) {
  int r = hash(size, x->key);
  if (r >= 0)
    list_insert(table[r], x);
}

void chained_hash_delete(sen_list **table, int k, int size) {
  int r = hash(size, k);
  if (r >= 0)
    list_delete(table[r], k);
}

void generate_nodes(node nodes[], int length, int array[]) {
  int i;
  for (i = 0; i < length; i++) {
    node *x = (node *) malloc(sizeof(node));
    malloc_error(x);
    x->key = array[i];
    x->next = NULL;
    x->prev = NULL;
    nodes[i] = *x;
  }
}

void print_list(sen_list *l) {
  node *x = l->nil->next;
  while (x != l->nil) {
    printf("%d", x->key);
    if (x->next != l->nil)
      printf("<-->");
    x = x->next;
  }
  printf(" | ");
}

void print_table(sen_list **table, int length) {
  int i;
  for (i = 0; i < length; i++) {
    print_list(table[i]);
  }
  printf("\n");
}

void generate_array(int array[], int length) {
  int i;
  srand((unsigned int) time(NULL));
  for (i = 0; i < length; i++)
    array[i] = rand() % length;
}

void print_array(int array[], int length) {
  int i;
  for (i = 0; i < length; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int compute_size(int length) {
  int a = length / 3;
  return (a % 2 == 0 ? (a + 1) : a);
}

int main() {
  int size, i = 0, n = 10;
  node nodes[n];
  int array[n];

  generate_array(array, n);
  print_array(array, n);
  generate_nodes(nodes, n, array);
  size = compute_size(n);
  sen_list **table = (sen_list **) malloc(size * sizeof(sen_list *));
  malloc_error(table);
  chained_hash_init(table, size);
  print_table(table, size);
  for (i = 0; i < n; i++) {
    chained_hash_insert(table, &nodes[i], size);
    print_table(table, size);
  }
  for (i = 0; i < n; i++) {
    node *x = chained_hash_search(table, nodes[i].key, size);
    printf("search = %d, result = %d\n", nodes[i].key, x->key);
  }
  for (i = 0; i < n; i++) {
    chained_hash_delete(table, nodes[i].key, size);
    print_table(table, size);
  }

  return 0;
}
