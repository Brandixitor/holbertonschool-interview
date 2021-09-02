#include "lists.h"
#include <stdio.h>
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: double linked list to check.
 * Return: 1 if it's palindrome otherwise 0.
 **/
int is_palindrome(listint_t **head)
{
	listint_t *oldHead = *head;
	int counter = 0, i = 0;
	int list[2048];

	for (i = 0; oldHead; i++)
		oldHead = oldHead->next;
	if (i == 0)
		return (1);
	oldHead = *head;
	for (counter = 0; oldHead; oldHead = oldHead->next, counter++)
		list[counter] = oldHead->n;
	for (counter = 0; counter < i; counter++)
	{
		if (list[counter] != list[i - counter - 1])
			return (0);
	}
	return (1);
}
