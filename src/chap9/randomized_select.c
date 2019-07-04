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

int randomized_select(int array[], int p, int r, int i) {
  if (p == r)
    return array[p];
  int q = randomized_partition(array, p, r);
  int k = q - p + 1;
  if (k == i)
    return array[q];
  if (i < k)
    return randomized_select(array, p, q - 1, i);
  else
    return randomized_select(array, q + 1, r, i - k);
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
  int i, n = 10, value;
  int array[n];

  generate_array(array, n);
  print_array(array, n);

  for (i = 1; i <= n; i++) {
    value = randomized_select(array, 0, n - 1, i);
    printf("index = %2d, value = %d\n", i, value);
  }

  randomized_quick_sort(array, 0, n - 1);
  print_array(array, n);

  return 0;
}
