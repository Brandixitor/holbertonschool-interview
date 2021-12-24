#include "sort.h"
/**
 * heapify - Builds a max-heap
 * @array: Array to sort
 * @size: Size of the array
 **/
void heapify(int *array, size_t size)
{
	int start = (int)((size - 1) / 2);

	while (start >= 0)
	{
		siftDown(array, start, size - 1, size);
		start -= 1;
	}
}
/**
 * siftDown - Sift the new first element to its appropriate index in the heap.
 * @array: Array to repair
 * @start: Root element
 * @end: Used for heap sort loop condition
 * @size: size of the array, used for printing on each iteration
 **/
void siftDown(int *array, int start, int end, int size)
{
	int root = start;
	int child = -1;
	int tmp = -1;

	/**
	 * Root must atleast have one left child if not, there is no need to check
	 ** for the right one
	 **/
	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		tmp = root;

		if (array[child] > array[tmp])
			tmp = child;
		if (child + 1 <= end && array[child + 1] > array[tmp])
			tmp = child + 1;
		if (tmp != root)
		{
			swap(array, root, tmp, size);
			root = tmp;
		}
		else
		{
			return;
		}
	}
}
/**
 * swap - Swaps two elements in the array
 * @array: Array on which the operation is done.
 * @first: Index of the first element to swap
 * @second: Index of the second element to swap
 * @size: number of elements in the array.
 **/
void swap(int *array, int first, int second, int size)
{
	int tmp;

	tmp = array[first];
	array[first] = array[second];
	array[second] = tmp;
	print_array(array, size);
}
/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 **/
void heap_sort(int *array, size_t size)
{
	int end = size - 1;

	heapify(array, size);
	/**
	 * Swaps the first element (greatest) with the last element
	 * until the array is sorted
	 **/
	while (end > 0)
	{
		swap(array, end, 0, size);
		end -= 1;
		siftDown(array, 0, end, size);
	}
}
