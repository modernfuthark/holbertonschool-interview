#include "lists.h"

/**
 * find_listint_loop - Finds a loop in a linked list
 * @head: Pointer to head node of list
 * Return: Pointer to node where the loop begins
 * NULL on error or if not found
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (!head || !head->next || !head->next->next)
		return (NULL);

	fast = head->next->next;
	slow = head->next;

	while (slow->next && fast->next->next)
	{
		if (slow == fast)
			break;
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
