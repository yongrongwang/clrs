#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void insertion_sort(int array[], int length) {
  int key, i, j;

  for (i = 1; i < length; i++) {
    key = array[i];
    for (j = i - 1; j >= 0 && key < array[j]; j--) {
      array[j + 1] = array[j];
    }
    array[j + 1] = key;
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

  insertion_sort(array, n);
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  printf("\n");

  return 0;
}
