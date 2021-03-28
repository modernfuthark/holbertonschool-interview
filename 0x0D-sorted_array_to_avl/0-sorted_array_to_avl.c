#include "binary_trees.h"

avl_t *createNode(avl_t *parent, int n);
void recursiveTree(int *array, size_t L, size_t R, avl_t *parent);

/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree
 * @array: Array to convert
 * @size: Size of array
 * Return: Pointer to root node, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int middle;

	if (size <= 0)
		return (NULL);

	if (size % 2 == 0)
		middle = (size / 2) - 1;
	else
		middle = size / 2;

	root = createNode(NULL, array[middle]);

	recursiveTree(array, 0, middle, root);
	recursiveTree(array, middle + 1, size, root);

	return (root);
}

/**
 * createNode - Creates a node
 * @parent: Parent node
 * @n: Value of node
 * Return: Pointer to new node
 */
avl_t *createNode(avl_t *parent, int n)
{
	avl_t *new = NULL;

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	if (parent)
	{
		if (new->n > parent->n)
			parent->right = new;
		else
			parent->left = new;
	}

	return (new);
}

/**
 * recursiveTree - Create an AVL tree recursivly
 * @array: Array to use
 * @l: Left value
 * @r: Right value
 * @parent: Parent node
 * Return: Nothing, function is void
 */
void recursiveTree(int *array, size_t l, size_t r, avl_t *parent)
{
	int middle;
	size_t size;
	avl_t *new = NULL;

	size = (r + 1) - l;
	middle = ((size / 2) - 1) + l;

	if (l < r)
	{
		new = createNode(parent, array[middle]);

		recursiveTree(array, l, middle, new);
		recursiveTree(array, middle + 1, r, new);
	}
}
