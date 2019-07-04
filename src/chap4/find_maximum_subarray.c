#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h> 
#include "find_maximum_subarray.h"

max_subarray find_max_crossing_subarray(
                int array[], int low, int mid, int high) {
  int i, j, left, right;
  int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0 ;

  for (i = mid; i >= low; i--) {
    sum += array[i];
    if (sum > left_sum) {
      left_sum = sum;
      left = i;
    }
  }
  sum = 0;
  for (j = mid + 1; j <= high; j++) {
    sum += array[j];
    if (sum > right_sum) {
      right_sum = sum;
      right = j;
    }
  }
  max_subarray max = {left, right, left_sum + right_sum};

  return  max;
}

max_subarray find_maximum_subarray(int array[], int low, int high) {
  if (low == high) {
    max_subarray max = {low, high, array[low]};
    return max;
  }
  else {
    int mid = (low + high) / 2;
    max_subarray max_left = find_maximum_subarray(array, low, mid);
    max_subarray max_right = find_maximum_subarray(array, mid + 1, high);
    max_subarray max_cross = find_max_crossing_subarray(array, low, mid, high);
    if (max_left.sum >= max_right.sum && max_left.sum >= max_cross.sum)
      return max_left;
    else if (max_right.sum >= max_left.sum && max_right.sum >= max_cross.sum)
      return max_right;
    else
      return max_cross;
  }
}

void generate_array(int array[], int length) {
  int i;
  srand((unsigned int) time(NULL));
  for (i = 0; i < length; i++) {
    if (i % 2 == 0)
      array[i] = -(rand() % length);
    else
      array[i] = rand() % length;
  }
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
  max_subarray max = find_maximum_subarray(array, 0, n - 1);
  printf("low = %d, high = %d, sum = %d", max.left, max.right, max.sum);
  printf("\n");

  return 0;
}
