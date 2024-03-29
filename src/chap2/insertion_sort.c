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
  insertion_sort(array, n);
  print_array(array, n);

  return 0;
}
