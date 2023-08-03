#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	
	if (tree == NULL)
		return 0;

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	
	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_balance - Measure the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 * Return: The balance factor of the tree, or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;
	
	if (tree == NULL)
		return 0;
	
	left_height = (int)binary_tree_height(tree->left);
	right_height = (int)binary_tree_height(tree->right);
	
	return (left_height - right_height);
}
