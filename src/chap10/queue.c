#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "queue.h"

int init_queue(queue *q, int size) {
  if ((q->array = (int *) malloc((size + 1) * sizeof(int))) == NULL)
    return 0;
  q->head = 1;
  q->tail = 1;
  q->size = size;
  return 1;
}

int queue_empty(queue *q) {
  return q->head == q->tail;
}

int queue_full(queue *q) {
  return q->head == q->tail + 1;
}

void enqueue(queue *q, int element) {
  if (queue_full(q)) {
    printf("queue is overflow\n");
    exit(0);
  }
  q->array[q->tail] = element;
  if (q->tail == q->size)
    q->tail = 1;
  else
    q->tail++;
}

int dequeue(queue *q) {
  if (queue_empty(q)) {
    printf("queue is underflow\n");
    exit(0);
  }
  int element = q->array[q->head];
  if (q->head == q->size)
    q->head = 1;
  else
    q->head++;
  return element;
}

void print_queue(queue *q) {
  int i = q->head;
  while (i != q->tail) {
    printf("%d ", q->array[i]);
    if (i == q->size)
      i = 1;
    else
      i++;
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
  srand((unsigned int) time(NULL));
  int r, value, i = 0, n = 10;
  int array[n];
  queue q;

  generate_array(array, n);
  print_array(array, n);
  if (!init_queue(&q, n)) {
    printf("allocate memory failed\n");
    exit(0);
  }

  while (i < n) {
    r = rand() % n;
    if (queue_empty(&q) || r < n / 2) {
      enqueue(&q, array[i]);
      printf("enqueue %d\n", array[i]);
      i++;
    }
    else {
      value = dequeue(&q);
      printf("dequeue %d\n", value);
    }
    print_queue(&q);
  }
  while (!queue_empty(&q)) {
    value = dequeue(&q);
    printf("dequeue %d\n", value);
    print_queue(&q);
  }

  return 0;
}
