#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: Pointer to first node of a linked list
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 **/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow;
	listint_t *fast;

	if (!head || !head->next)
		return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (fast && fast->next && slow != fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		return (NULL);

	slow = head;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}
