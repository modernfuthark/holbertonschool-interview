#include "binary_trees.h"

size_t tree_size(heap_t *tree);

/**
 * heap_insert - Insert into a Max Binary Heap
 * @root: Root of binary tree
 * @value: Value of new node
 * Return: New node, null on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	size_t leftSize, rightSize, temp;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new = binary_tree_node(NULL, value);
		*root = new;
		return (new);
	}

	/* Get size of tree's sides */
	leftSize = tree_size((*root)->left);
	rightSize = tree_size((*root)->right);

	if (leftSize == rightSize)
	{
		new = heap_insert(&(*root)->left, value);
		if (!new->parent)
		{
			(*root)->left = new;
			new->parent = *root;
		}
		if (new->parent->n < new->n)
		{
			temp = new->n;
			new->n = new->parent->n;
			new->parent->n = temp;
			return (new->parent);
		}
		else
			return (new);
	}
	else
	{
		new = heap_insert(&(*root)->right, value);
		if (!new->parent)
		{
			(*root)->right = new;
			new->parent = *root;
		}
		if (new->parent->n < new->n)
		{
			temp = new->n;
			new->n = new->parent->n;
			new->parent->n = temp;
			return (new->parent);
		}
		else
			return (new);
	}
}

/**
 * tree_size - Gets the size of a binary tree
 * @tree: Tree to measure
 * Return: Length of tree, 0 if not given
 */
size_t tree_size(heap_t *tree)
{
	if (tree)
		return (tree_size(tree->left) + tree_size(tree->right) + 1);
	return (0);
}
