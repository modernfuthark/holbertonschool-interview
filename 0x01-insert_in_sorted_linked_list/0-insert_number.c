#include "lists.h"

/**
 * insert_node - Inserts a node into a sorted LList
 * @head: Head of list
 * @number: Number to add to list
 * Return: Address of new node
 * NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *temp;
	/* I think its a good time to start commenting my code lol */
	/* Allocate memory for both lists */
	temp = malloc(sizeof(listint_t));
	new = malloc(sizeof(listint_t));
	if (!temp || !new || !head) /* Bulk NULL checking */
		return (NULL);

	/* Got past NULL checking, create new node */
	new->n = number;
	new->next = NULL;

	if (!*head)
	{ /* If list head doesn't exist, make one and return */
		*head = new;
		return (new);
	}
	temp = *head;

	if (number < temp->n)
	{ /* if head > number, make new node the head */
		new->next = *head;
		*head = new;
		return (new);
	}

	while (temp->next)
	{ /* While loop since we don't know how big the list is */
		if ((temp->next)->n >= number)
		{ /* If next node is greater than number, move list down one and return */
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		temp = temp->next;
	}
	/* No bigger numbers in list, add to end of list */
	temp->next = new;
	return (new);
}
