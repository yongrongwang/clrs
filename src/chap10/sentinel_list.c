#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sentinel_list.h"

#define NIL -1

void malloc_error(void *p) {
  if (!p) {
    printf("error: malloc memory failed\n");
    exit(0);
  }
}

sen_list init_list() {
  sen_list *l = (sen_list *) malloc(sizeof(sen_list));
  malloc_error(l);
  node *x = (node *) malloc(sizeof(node));
  malloc_error(x);
  l->nil = x;
  l->nil->key = NIL;
  l->nil->next = l->nil;
  l->nil->prev = l->nil;
  return *l;
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

void list_delete(node *x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
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

int main() {
  int i = 0, n = 10;
  int array[n];
  node nodes[n];

  sen_list l = init_list();
  generate_array(array, n);
  print_array(array, n);
  generate_nodes(nodes, n, array);
  for (i = 0; i < n; i++) {
    list_insert(&l, &nodes[i]);
    print_list(&l);
  }
  for (i = 0; i < n; i++) {
    node *x = list_search(&l, array[i]);
    printf("search = %d, result = %d\n", array[i], x->key);
  }
  for (i = 0; i < n; i++) {
    list_delete(&nodes[i]);
    print_list(&l);
  }

  return 0;
}
