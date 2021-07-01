#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_begin - Adds a node at the start of @list
 * @list: List to add to
 * @str: String of new node
 * Return: Address of new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *newNode, *head, *tail;

	if (!str)
		return (NULL);

	newNode = malloc(sizeof(List));
	if (!newNode)
		return (NULL);

	newNode->str = strdup(str);
	if (!newNode->str)
		return (NULL);

	newNode->next = *(list);
	newNode->prev = NULL;

	if (!*list)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
	}
	else
	{
		head = *list;
		tail = (*list)->prev;

		head->prev = newNode;
		tail->next = newNode;

		newNode->next = head;
		newNode->prev = tail;
	}

	*list = newNode;
	return (newNode);
}

/**
 * add_node_end - Adds a node at the end of @list
 * @list: List to add to
 * @str: String of new node
 * Return: Address of new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *newNode, *head, *tail;

	if (!str)
		return (NULL);

	newNode = malloc(sizeof(List));
	if (!newNode)
		return (NULL);

	newNode->str = strdup(str);
	if (!newNode->str)
		return (NULL);

	newNode->next = *(list);
	newNode->prev = NULL;

	if (!*list)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
	}
	else
	{
		head = *list;
		tail = (*list)->prev;

		head->prev = newNode;
		tail->next = newNode;

		newNode->next = head;
		newNode->prev = tail;
	}
	return (newNode);
}
