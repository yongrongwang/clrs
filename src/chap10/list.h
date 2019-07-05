#ifndef LIST_H
#define LIST_H

typedef struct node_struct node;
struct node_struct{
  int key;
  node *next;
  node *prev;
};

typedef struct {
  node *head;
} list;

void malloc_error(void *p);
list init_list();
node *list_search(list *l, int element);
void list_insert(list *l, node *x);
void list_delete(list *l, node *x);
void print_list(list *l);
void generate_nodes(node nodes[], int length, int array[]);
void generate_array(int array[], int length);
void print_array(int array[], int length);

#endif
