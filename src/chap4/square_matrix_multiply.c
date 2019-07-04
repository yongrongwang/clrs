#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

void square_matrix_multiply(int n, int a[n][n], int b[n][n], int c[n][n]) {
  int i, j, k;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = 0;
      for (k = 0; k < n; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
  }
}

void generate_2d_array(int n, int a[n][n]) {
  int i, j;
  srand((unsigned int) time(NULL));
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = rand() % n;
    }
  }
}

void print_2d_arrary(int n, int a[n][n]) {
  int i, j;
  srand((unsigned int) time(NULL));
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%3d ", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  int n = 10;
  int a[n][n], b[n][n], c[n][n];

  generate_2d_array(n, a);
  print_2d_arrary(n, a);
  generate_2d_array(n, b);
  print_2d_arrary(n, b);
  square_matrix_multiply(n, a, b, c);
  print_2d_arrary(n, c);

  return 0;
}
