#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"

void malloc_error(void *p) {
  if (!p) {
    printf("error: malloc memory failed\n");
    exit(0);
  }
}

list init_list() {
  list *l = (list *) malloc(sizeof(list));
  malloc_error(l);
  l->head = NULL;
  return *l;
}

node *list_search(list *l, int element) {
  node *x = l->head;
  while (x != NULL && x->key != element)
    x = x->next;
  return x;
}

void list_insert(list *l, node *x) {
  x->next = l->head;
  if (l->head != NULL)
    l->head->prev = x;
  l->head = x;
  x->prev = NULL;
}

void list_delete(list *l, node *x) {
  if (x->prev != NULL)
    x->prev->next = x->next;
  else
    l->head = x->next;
  if (x->next != NULL)
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

void print_list(list *l) {
  node *x = l->head;
  while (x != NULL) {
    printf("%d", x->key);
    if (x->next != NULL)
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

  list l = init_list();
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
    list_delete(&l, &nodes[i]);
    print_list(&l);
  }

  return 0;
}

