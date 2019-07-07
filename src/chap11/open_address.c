#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NIL -1

void chained_hash_init(int table[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    table[i] = NIL;
  }
}

int double_hash(int size, int k, int i) {
  int h1 = k % size;
  int h2 = 1 + k % (size - 1);
  return (h1 + i * h2) % size;
}

int chained_hash_search(int table[], int k, int size) {
  int i = 0, j;

  do {
    j = double_hash(size, k, i);
    if (table[j] == k)
      return j;
    else
      i++;
  } while (table[j] != NIL && i != size);

  return NIL;
}

int chained_hash_insert(int table[], int k, int size) {
  int i = 0, j;
  while (i != size) {
    j = double_hash(size, k, i);
    if (table[j] == NIL) {
      table[j] = k;
      return j;
    }
    else {
      i++;
    }
  }
  return -1;
}

void print_table(int table[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", table[i]);
  }
  printf("\n");
}

void generate_array(int array[], int length) {
  int i;
  srand((unsigned int) time(NULL));
  for (i = 0; i < length; i++)
    array[i] = rand() % (6 * length);
}

void print_array(int array[], int length) {
  int i;
  for (i = 0; i < length; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int compute_size(int length) {
  int a = length * 3;
  return (a % 2 == 0 ? (a + 1) : a);
}

int main() {
  int i = 0, j, n = 10;
  int array[n];
  int size = compute_size(n);
  int table[size];

  generate_array(array, n);
  print_array(array, n);
  chained_hash_init(table, size);
  print_table(table, size);
  for (i = 0; i < n; i++) {
    chained_hash_insert(table, array[i], size);
    print_table(table, size);
  }
  for (i = 0; i < n; i++) {
    j = chained_hash_search(table, array[i], size);
    printf("search = %d, result = %d\n", array[i], table[j]);
  }

  return 0;
}
