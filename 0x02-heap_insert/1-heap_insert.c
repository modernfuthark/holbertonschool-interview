#include "binary_trees.h"

size_t tree_size(heap_t *tree);
void place_node();

/**
 * heap_insert - Insert into a Max Binary Heap
 * @root: Root of binary tree
 * @value: Value of new node
 * Return: New node, null on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	size_t size = 0;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}

	/* Get size of tree */
	size = tree_size(*root);
}


size_t tree_size(heap_t *tree)
{
	if (tree)
		return (tree_size(tree->left) + tree_size(tree->right) + 1);
	return (0);
}
