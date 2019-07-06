#ifndef FIND_MAXIMUM_SUBARRAY_H
#define FIND_MAXIMUM_SUBARRAY_H

typedef struct{
  int left;
  int right;
  int sum;
} subarray;

subarray find_max_crossing_subarray(int array[], int low, int mid, int high);
subarray find_maximum_subarray(int array[], int low, int high);

#endif
