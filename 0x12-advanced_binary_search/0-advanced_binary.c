#include "search_algos.h"
/**
 * print_array - Prints an array of integers
 * @array: is a pointer to the first element of the array
 * @start: From where we start printing
 * @end: Where to stop printing
 **/
void print_array(int *array, size_t start, size_t end)
{
	size_t i = start;

	printf("Searching in array: ");
	while (i <= end)
	{
		printf("%d", array[i]);
		if (i != end)
		{
			printf(", ");
		}
		i++;
	}
	printf("\n");
}
/**
 * binary_search - Recursive function to find the first value in
 * a sorted array
 * @array: is a pointer to the first element of the array to search in
 * @start: Where to start searching
 * @end: Where search ends
 * @value: is the value to search for
 * Return: position of the finded element, if no element
 * has been found it will returns -1
 **/
int binary_search(int *array, size_t start, size_t end, int value)
{
	size_t midValue = (int)((start + end) / 2);

	print_array(array, start, end);

	if (value == array[start])
		return (start);
	else if (midValue >= end)
		return (-1);
	else if (value <= array[midValue - 1])
	{
		return (binary_search(array, start, midValue, value));
	}
	else if (value >= array[midValue + 1])
	{
		return (binary_search(array, midValue + 1, end, value));
	}
	return (-1);
}
/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * it should return the first occurance in the array
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: returns the index where value is located otherwise
 * if the value is not present in array or if the array is NULL, it returns -1
 **/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}
