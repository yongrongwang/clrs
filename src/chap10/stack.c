#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "stack.h"

int init_stack(stack *s, int size) {
  if ((s->array = (int *) malloc((size + 1) * sizeof(int))) == NULL)
    return 0;
  s->top = 0;
  s->size = size;
  return 1;
}

int stack_empty(stack *s) {
  return s->top == 0;
}

int stack_full(stack *s) {
  return s->top == s->size;
}

void push(stack *s, int element) {
  if (stack_full(s)) {
    printf("stack is overflow\n");
    exit(0);
  }
  s->array[++s->top] = element;
}

int pop(stack *s) {
  if (stack_empty(s)) {
    printf("stack is underflow\n");
    exit(0);
  }
  int element = s->array[s->top--];
  return element;
}

void print_stack(stack *s) {
  int i;
  for (i = 1; i <= s->top; i++)
    printf("%d ", s->array[i]);
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
  srand((unsigned int) time(NULL));
  int r, value, i = 0, n = 10;
  int array[n];
  stack s;

  generate_array(array, n);
  print_array(array, n);
  if (!init_stack(&s, n)) {
    printf("allocate memory failed\n");
    exit(0);
  }
  while (i < n) {
    r = rand() % n;
    if (stack_empty(&s) || r < n / 2) {
      push(&s, array[i]);
      printf("push %d\n", array[i]);
      i++;
    }
    else {
      value = pop(&s);
      printf("pop %d\n", value);
    }
    print_stack(&s);
  }
  while (!stack_empty(&s)) {
    value = pop(&s);
    printf("pop %d\n", value);
    print_stack(&s);
  }

  return 0;
}
