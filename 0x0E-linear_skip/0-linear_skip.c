#include "search.h"

/**
 * pChecked - Prints the index and value on which the value is checked.
 * @first: index.
 * @second: value
 **/
void pChecked(size_t first, int second)
{
	printf("Value checked at index [%ld] = [%d]\n", first, second);
}

/**
 * search - Search and prints between which indexes
 * the value has been found
 * @nlane: Lane on which we check the value
 * @f: first index value
 * @s: second index value
 * @value: Value to search
 *
 * Return: Pointer to node's value.
 **/
skiplist_t *search(skiplist_t *nlane, size_t f, size_t s, int value)
{
	printf("Value found between indexes [%ld] and [%ld]\n", f, s);
	while (nlane)
	{
		pChecked(nlane->index, nlane->n);
		if (nlane->n == value)
		{
			return (nlane);
		}
		nlane = nlane->next;
	}
	return (NULL);
}


/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return: pointer on the first node where value is located
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express;
	skiplist_t *lastExpress;
	size_t index;

	if (list == NULL)
		return (NULL);

	express = list->express;

	if (express->n >= value)
	{
		pChecked(express->index, express->n);
		return (search(list, list->index, express->index, value));
	}

	while (express->next)
	{
		if (express->express)
		{
			pChecked(express->index, express->n);
			lastExpress = express->express;
		}
		if (express->express && express->express->n >= value)
		{
			pChecked(express->express->index, express->express->n);
			index = express->express->index;
			return (search(express, express->index, index, value));
		}
		express = express->next;
	}

	pChecked(lastExpress->index, lastExpress->n);
	return (search(lastExpress, lastExpress->index, express->index, value));
}
