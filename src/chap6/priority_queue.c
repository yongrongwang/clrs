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

int heap_maximum(int array[]) {
  return array[1];
}

int extract_max(int array[]) {
  if (heap_size < 1) {
    printf("error: heap under flow\n");
    exit(0);
  }
  int max = array[1];
  array[1] = array[heap_size];
  heap_size--;
  max_heapify(array, 1);

  return max;
}

void heap_increase_key(int array[], int index, int key) {
  if (key < array[index]) {
    printf("error: new key is smaller than current key\n");
    exit(0);
  }
  array[index] = key;
  while (index > 1 && array[index] > array[PARENT(index)]) {
    swap(&array[index], &array[PARENT(index)]);
    index = PARENT(index);
  }
}

void max_heap_insert(int array[], int key) {
  heap_size++;
  array[heap_size] = INT_MIN;
  heap_increase_key(array, heap_size, key);
}

void generate_array(int array[], int length) {
  int i;
  srand((unsigned int) time(NULL));
  for (i = 1; i <= length; i++)
    array[i] = rand() % length;
}

void print_array(int array[], int length) {
  int i;
  for (i = 1; i <= length; i++)
    printf("%d ", array[i]);
  printf("\n");
}

void print_heap(int array[]) {
  int i;
  for (i = 1; i <= heap_size; i++)
    printf("%d ", array[i]);
  printf("\n");

}

int main() {
  int n = 10, max, key, key2, index;
  int array[n + 1];

  generate_array(array, n);
  print_array(array, n);
  build_max_heap(array, n);
  max = heap_maximum(array);
  printf("max = %d\n", max);
  print_heap(array);

  printf("extracted = %d\n", extract_max(array));
  print_heap(array);

  index = (rand()) % heap_size + 1;
  key = max + 1;
  heap_increase_key(array, index, key);
  printf("increased = %d, index = %d\n", key, index);
  print_heap(array);

  key2 = max + 2;
  max_heap_insert(array, key2);
  printf("inserted = %d\n", key2);
  print_heap(array);

  return 0;
}

