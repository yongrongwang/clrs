#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
  int head;
  int tail;
  int size;
  int *array;
} queue;

int init_queue(queue *q, int size);
int queue_empty(queue *q);
int queue_full(queue *q);
void enqueue(queue *q, int element);
int dequeue(queue *q);
void print_queue(queue *q);
void generate_array(int array[], int length);
void print_array(int array[], int length);

#endif
