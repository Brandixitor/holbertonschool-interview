#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/* Our own functions */
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

/**
* _print_array - Prints an array of integers
*
* @array: The array to be printed
* @size: Size of the array
*/
void _print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		printf("(%03d)", array[i]);
	printf("\n");
}

/**
* main - Entry point
*
* Return: 0 on success, error code on failure
*/
int main(void)
{
	avl_t *root;
	int array[] = {
		2, 12, 15, 33, 38, 44, 46, 48, 57, 58, 60, 63, 71, 74, 84
	};
	size_t n = sizeof(array) / sizeof(array[0]);

	root = sorted_array_to_avl(array, n);

	_print_array(array, n);
	binary_tree_print(root);
	_binary_tree_delete(root);
	return (0);
}