#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

void merge(int array[], int p, int q, int r) {
  int n1 = q - p + 1, n2 = r - q, i, j, k;
  int left[n1 + 1], right[n2 + 1];

  for (i = 0; i < n1; i++)
    left[i] = array[p + i];
  for (j = 0; j < n2; j++)
    right[j] = array[q + j + 1];
  left[n1] = right[n2] = INT_MAX;

  i = j = 0;
  for (k = p; k <= r; k++) {
    if (left[i] <= right[j]) {
      array[k] = left[i++];
    }
    else {
      array[k] = right[j++];
    }
  }
}

void merge_sort(int array[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(array, p, q);
    merge_sort(array, q + 1, r);
    merge(array, p, q, r);
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
  merge_sort(array, 0, n - 1);
  print_array(array, n);

  return 0;
}
