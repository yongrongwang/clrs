#ifndef STACK
#define STACK

typedef struct {
  int top;
  int size;
  int *array;
} stack;

int init_stack(stack *s, int size);
int stack_empty(stack *s);
int stack_full(stack *s);
void push(stack *s, int element);
int pop(stack *s);
void print_stack(stack *s);
void generate_array(int array[], int length);
void print_array(int array[], int length);

#endif
