#ifndef FIND_MAXIMUM_SUBARRAY
#define FIND_MAXIMUM_SUBARRAY

typedef struct max{
  int left;
  int right;
  int sum;
} max_subarray;

max_subarray find_max_crossing_subarray(int array[], int low, int mid, int high);
max_subarray find_maximum_subarray(int array[], int low, int high);

#endif
