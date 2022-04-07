#ifndef RADIX_SORT
#define RADIX_SORT

#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int getMax(int *array, int n);

#endif
