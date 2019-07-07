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

void malloc_error(void *p);
void init_list(sen_list *l);
void chained_hash_init(sen_list ** table, int size);
node *list_search(sen_list *l, int element);
void list_insert(sen_list *l, node *x);
void list_delete(sen_list *l, int k);
int hash(int size, int k);
node *chained_hash_search(sen_list **table, int k, int size);
void chained_hash_insert(sen_list **table, node *x, int size);
void chained_hash_delete(sen_list **table, int k, int size);
void generate_nodes(node nodes[], int length, int array[]);
void print_list(sen_list *l);
void print_table(sen_list **table, int length);
void generate_array(int array[], int length);
void print_array(int array[], int length);
int compute_size(int length);

#endif
