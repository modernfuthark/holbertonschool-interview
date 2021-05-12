#include "binary_trees.h"

heap_t *get_last_node(heap_t *root);
size_t tree_height(heap_t *root);
void rearrange_tree(heap_t *root);

/**
 * heap_extract - Extracts the root of a max binary heap
 * @root: Double pointer to tree's root node
 * Return: Value of root, 0 on failiure
 */
int heap_extract(heap_t **root)
{
	heap_t *old_node = NULL;
	heap_t *last_node = NULL;
	int old_value;

	if (!root || !(*root))
		return (0);

	old_node = *root;
	old_value = old_node->n;
	last_node = get_last_node(old_node);

	if (old_node == last_node)
	{
		*root = NULL;
		free(old_node);
		return (old_value);
	}

	if (last_node->parent->right)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	old_node->n = last_node->n;

	rearrange_tree(old_node);

	free(last_node);

	return (old_value);
}

/**
 * get_last_node - Gets the last node of a binary tree
 * @root: Root of tree
 * Return: Pointer to last node, NULL on failiure
 */
heap_t *get_last_node(heap_t *root)
{
	if (!root)
		return (NULL);

	if (!root->left && !root->right)
		return (root);
	if (tree_height(root->left) > tree_height(root->right))
		return (get_last_node(root->left));

	return (get_last_node(root->right));
}

/**
 * tree_height - Returns the height of a binary tree
 * @root: Root of tree
 * Return: Height of tree, 0 on failiure
 */
size_t tree_height(heap_t *root)
{
	size_t L = 0;
	size_t R = 0;

	if (!root)
		return (0);

	L = tree_height(root->left) + 1;
	R = tree_height(root->right) + 1;


	if (L > R)
		return (L);
	return (R);
}

/**
 * rearrange_tree - Rearranges a binary tree
 * @root: Root of tree
 * Return: Nothing, function is void
 */
void rearrange_tree(heap_t *root)
{
	heap_t *largest = NULL;
	int temp;

	if (!root)
		return;

	if (root->right && root->right->n > root->left->n)
		largest = root->right;
	else if (root->left)
		largest = root->left;

	if (largest && largest->n > root->n)
	{
		temp = largest->n;
		largest->n = root->n;
		root->n = temp;
		rearrange_tree(largest);
	}
}
