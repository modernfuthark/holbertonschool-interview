#include "search.h"
#include <math.h>

/**
 * linear_skip - Search a skip list for a value
 * @list: Head of list to search through
 * @value: Value to find
 * Return: Pointer to node with value, NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp, *last;

	if (!list)
		return (NULL);

	temp = list;
	last = getLastNode(list);

	if (temp->express && temp->express->n >= value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		temp->express->index, temp->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		temp->index, temp->express->index);
		return (getValue(temp, value));
	}
	/* Express skipping */

	while (temp)
	{
		temp = temp->express;
		printf("Value checked at index [%lu] = [%d]\n", temp->index, temp->n);
		if (!temp->express)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			temp->index, last->index);
			break;
		}
		if (temp->express->n >= value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			temp->express->index, temp->express->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			temp->index, temp->express->index);
			break;
		}
	}
	return (getValue(temp, value));
}

/**
 * getValue - Search for value in list
 * @list: List to search
 * @value: Value to find
 * Return: Pointer to node with value
 */
skiplist_t *getValue(skiplist_t *list, int value)
{
	if (list)
	{
		while (list)
		{
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			if (list->n == value)
			{
				return (list);
			}
			else
				list = list->next;
		}
	}
	return (list);
}

/**
 * getLastNode - Gets the last node in list
 * @list: List to pass through
 * Return: Last node in list
 */
skiplist_t *getLastNode(skiplist_t *list)
{
	if (!list->next)
		return (list);
	else
		return (getLastNode(list->next));
}
