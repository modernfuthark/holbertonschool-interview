#include "lists.h"

int recursive_check(listint_t *one, listint_t *two);

/**
 * check_cycle - Checks if there is a loop in a linked list
 * @list: Head node
 * Return: 1 if there is a cycle, 0 if none are present
 */
int check_cycle(listint_t *list)
{
	if (!list || !list->next)
		return (0);

	return (recursive_check(list, list->next));
}

/**
 * recursive_check - Checks for a loop in a linked list recursivly
 * @one: Node one
 * @two: Node two
 * Return: 1 if there is a cycle, 0 if none are present
 */
int recursive_check(listint_t *one, listint_t *two)
{
	if (!one || !two || !two->next)
		return (0);

	if (one == two)
		return (1);

	return (recursive_check(one->next, two->next->next));
}
