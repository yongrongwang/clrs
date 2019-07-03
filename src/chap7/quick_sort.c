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

void quick_sort(int array[], int p, int r) {
  if (p < r) {
    int q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
  }
}

int main() {
  int i, n = 10;
  int array[n];

  srand((unsigned int) time(NULL));
  for (i = 0; i < n; i++) {
    array[i] = rand() % n;
    printf("%d ", array[i]);
  }
  printf("\n");

  quick_sort(array, 0, n - 1);
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  printf("\n");

  return 0;
}
