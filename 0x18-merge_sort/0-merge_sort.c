#include "sort.h"

/**
 * topDown_Merge - Splitting array for a merge.
 * @array: Array to sort
 * @start: From where we start operations
 * @mid: Mid point
 * @end: Where to end operations
 * @copy: Array to work on
 **/
void topDown_Merge(int *array, int start, int mid, int end, int *copy)
{
	int s = start;
	int m = mid;
	int i = 0;

	for (i = start; i < end; i++)
	{

		if (s < mid && (m >= end || copy[s] <= copy[m]))
		{
			array[i] = copy[s];
			s = s + 1;
		}
		else
		{
			array[i] = copy[m];
			m = m + 1;
		}
	}
}

/**
 * topDown_SplitMerge - Splitting array for a merge.
 * @array: Array to sort
 * @start: From where we start operations
 * @end: Where to end operations
 * @copy: Array to work on
 **/
void topDown_SplitMerge(int *array, int start, int end, int *copy)
{
	int mid = (start + end) / 2;
	int i = 0;

	if (end - start <= 1)
		return;

	topDown_SplitMerge(copy, start, mid, array);
	topDown_SplitMerge(copy, mid, end, array);
	printf("Merging...\n");

	printf("[left]: ");
	for (i = start; i < mid; i++)
	{
		printf("%d", copy[i]);
		if (i < mid - 1)
			printf(", ");
	}

	printf("\n[right]: ");
	for (i = mid; i < end; i++)
	{
		printf("%d", copy[i]);
		if (i < end - 1)
			printf(", ");
	}

	topDown_Merge(array, start, mid, end, copy);

	printf("\n");
	printf("[Done]: ");
	for (i = start; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n");
}
/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * @array: Array to sort
 * @size: Size of array
 **/
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i = 0;

	copy = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	topDown_SplitMerge(array, 0, size, copy);
	free(copy);
}
