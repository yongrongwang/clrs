#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int p, int r) {
  int i = p - 1, j;
  int pivot = array[r];
  for (j = p; j < r; j++) {
    if (array[j] < pivot) {
      swap(&array[++i], &array[j]);
    }
  }
  swap(&array[++i], &array[r]);
  return i;
}

int randomized_partition(int array[], int p, int r) {
  srand((unsigned int) time(NULL));
  int i = p + rand() % (r - p + 1);
  swap(&array[i], &array[r]);
  return partition(array, p, r);
}

void randomized_quick_sort (int array[], int p, int r) {
  if (p < r) {
    int q = randomized_partition(array, p, r);
    randomized_quick_sort(array, p, q - 1);
    randomized_quick_sort(array, q + 1, r);
  }
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
  int n = 10;
  int array[n];

  generate_array(array, n);
  print_array(array, n);
  randomized_quick_sort(array, 0, n - 1);
  print_array(array, n);

  return 0;
}
