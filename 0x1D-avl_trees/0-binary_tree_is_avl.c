#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_avl - Checks to see if a binary tree is an AVL tree
 * @tree: Binary tree
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bal = 0;

	if (!tree)
		return (0);

	if (recur_bst_check(tree, INT_MIN, INT_MAX))
	{
		bal = tree_balance(tree);
		if (bal == 0)
			return (1);
	}
	return (0);
}

/**
 * recur_bst_check - Recursivly check if a tree is BST
 * @tree: Tree to check
 * @min: Minimum
 * @max: Maximum
 * Return: 1 if tree is BST, 0 if not
 */
int recur_bst_check(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if ((tree->n < min) || (tree->n > max))
		return (0);

	return (recur_bst_check(tree->left, min, tree->n - 1)
			&& recur_bst_check(tree->right, tree->n + 1, max));
}

/**
 * tree_balance - Recursive tree balance check
 * @tree: Tree to check
 * Return: Balance factor of tree
 */
int tree_balance(const binary_tree_t *tree)
{
	int balanceFactor;

	if (!tree)
		return (0);

	balanceFactor = get_balance(tree);

	if (balanceFactor > 1 || balanceFactor < -1)
		return (balanceFactor);

	return (tree_balance(tree->left) || tree_balance(tree->right));
}

/**
 * get_balance - Checks the balance factor of a tree
 * @tree: Tree to check
 * Return: Balance factor of binary tree
 */
int get_balance(const binary_tree_t *tree)
{
	int L = 0, R = 0;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);

	L = get_height(tree->left) - 1;
	R = get_height(tree->right) - 1;

	return (L - R);
}

/**
 * get_height - Gets the height of a binary tree
 * @tree: Tree to measure
 * Return: Height of @tree
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t R, L;

	if (!tree)
		return (0);

	L = get_height(tree->left);
	R = get_height(tree->right);

	if (L > R)
		return (L + 1);
	else
		return (R + 1);
}
