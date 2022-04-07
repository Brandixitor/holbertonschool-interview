#include "sort.h"
/**
* getMax - get max value
* @array:array to be sorted
* @n: size of array
* Return: integer, max number of array
*/
int getMax(int *array, int n)
{
	int i, max;

	for (max = array[0], i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}
/**
* countSort - counting sort of arr[] according to the digit represented by exp
* @array:array to be sorted
* @n:size of array
* @exp: exponential
* Return - None
*/
void countSort(int *array, int n, int exp)
{
	int *output, i, count[10] = { 0 };

	output = malloc(sizeof(int) * n);
	if (output == NULL)
		return;
	/*Store count of occurrences in count[]*/
	for (i = 0; i < n; i++)
		count[(array[i] / exp) % 10]++;

	/*Change count[i] so that count[i] now contains actual*/
	/*position of this digit in output[]*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/*Build the output array*/
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/*Copy the output array to arr[], so that arr[] now*/
	/*contains sorted numbers according to current digit*/
	for (i = 0; i < n; i++)
		array[i] = output[i];
	free(output);
}
/**
* radix_sort - sort an array
* @array:array to be sorted
* @size:size of array
* Return - None
*/
void radix_sort(int *array, size_t size)
{
	/*Find the maximum number to know number of digits*/
	int exp, m;

	if (size < 2)
		return;
	m = getMax(array, size);
	/* Do counting sort for every digit. Note that instead */
	/* of passing digit number, exp is passed. exp is 10^i */
	/* where i is current digit number */
	for (exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
