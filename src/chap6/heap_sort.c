#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

//array[0] isn't included in heap
#define PARENT(i)  ((i) / 2)
#define LEFT(i)    (2 * (i))
#define RIGHT(i)   (2 * (i)  +1)

int heap_size;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void max_heapify(int array[], int index) {
  int left = LEFT(index);
  int right = RIGHT(index);
  int largest = index;
  if (left <= heap_size && array[largest] < array[left])
    largest = left;
  if (right <= heap_size && array[largest] < array[right])
    largest  =right;
  if (largest != index) {
    swap(&array[index], &array[largest]);
    max_heapify(array, largest);
  }
}

void build_max_heap(int array[], int length) {
  int i;
  heap_size = length;
  for (i = length / 2; i >= 1; i--)
    max_heapify(array, i);
}

void heap_sort(int array[], int length) {
  int i;

  build_max_heap(array, length);
  for (i = length; i >= 2; i--) {
    swap(&array[i], &array[1]);
    heap_size--;
    max_heapify(array, 1);
  }
}

int main() {
  int i, n = 10;
  int array[n + 1];

  srand((unsigned int) time(NULL));
  for (i = 1; i <= n; i++) {
    array[i] = rand() % n;
    printf("%d ", array[i]);
  }
  printf("\n");

  heap_sort(array, n);
  for (i = 1; i <= n; i++)
    printf("%d ", array[i]);
  printf("\n");

  return 0;
}
