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

int main() {
  int i, j, n = 10;
  int a[n][n], b[n][n], c[n][n];

  srand((unsigned int) time(NULL));
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = rand() % n;
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      b[i][j] = rand() % n;
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  square_matrix_multiply(n, a, b, c);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", c[i][j]);
      if (c[i][j] < 10)
        printf(" ");
      if (c[i][j] < 100)
        printf(" ");
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}
