#include "search.h"
#include <math.h>

skiplist_t *getValue(skiplist_t *list, int value);
skiplist_t *getLastNode(skiplist_t *list);

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
		printf("Value checked at index [%lu] = [%d]\n", temp->express->index, temp->express->n);
		printf("Value found between [%lu] and [%lu]\n", temp->index, temp->express->index);
		return (getValue(temp, value));
	}
	/* Express skipping */

	while (temp)
	{
		temp = temp->express;
		printf("Value checked at index [%lu] = [%d]\n", temp->index, temp->n);
		if (!temp->express)
		{
			printf("Value found between [%lu] and [%lu]\n", temp->index, last->index);
			break;
		}
		if (temp->express->n >= value)
		{
			printf("Value checked at index [%lu] = [%d]\n", temp->express->index, temp->express->n);
			printf("Value found between [%lu] and [%lu]\n", temp->index, temp->express->index);
			break;
		}
	}

	//printf("debug node info before getValue: index[%lu] value[%d]\n", temp->index, temp->n);
	//temp = getValue(temp, value);
	//printf("debug node info after getValue: index[%lu] value[%d]\n", temp->index, temp->n);
	//if (temp)
	//	return (temp);
	return (getValue(temp, value));
}

skiplist_t *getValue(skiplist_t *list, int value)
{
	if (list)
	{
		while (list)
		{
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			if (list->n == value)
			{
				//printf("Found %d at index: %lu\n", value, list->index);
				return (list);
			}
			else
				//getValue(list->next, value);
				list = list->next;
		}
	}
	//printf("Found %d at index: (nil)", value);
	return (list);
}

skiplist_t *getLastNode(skiplist_t *list)
{
	if (!list->next)
		return (list);
	else
		return (getLastNode(list->next));
}