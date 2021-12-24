#ifndef sort_h
#define sort_h
#include <stdio.h>
void print_array(const int *array, size_t size);
void swap(int *array, int first, int second, int size);
void siftDown(int *array, int start, int end, int size);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
#endif
