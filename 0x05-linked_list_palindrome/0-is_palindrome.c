#include "lists.h"
#include <stdio.h>

int recursive_palindrome(listint_t **left, listint_t *right);

/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: Head of list
 * Return: 1 if list is a palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	if (!*head || !(*head)->next)
		return (1);

	return (recursive_palindrome(head, *head));
}

/**
 * recursive_palindrome - Recursivly compares both ends of a linked list
 * @left: Left node
 * @right: Right node
 * Return: 1 if nodes match, 0 if not
 */
int recursive_palindrome(listint_t **left, listint_t *right)
{
	int judge = 0;

	if (!right)
		return (1);

	if (!recursive_palindrome(left, right->next))
		return (0);

	judge = (right->n == (*left)->n);
	/*printf("DEBUG | Comparing %d and %d...\n", right->n, (*left)->n);*/
	*left = (*left)->next;

	return (judge);
}
