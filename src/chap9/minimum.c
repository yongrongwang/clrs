#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

int minimum(int array[], int length) {
  int i, min = array[0];
  for (i = 1; i < length; i++)
    if (array[i] < min)
      min = array[i];
  return min;
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
  int min, n = 10;
  int array[n];

  generate_array(array, n);
  print_array(array, n);
  min = minimum(array, n);
  printf("min = %d\n", min);

  return 0;
}
