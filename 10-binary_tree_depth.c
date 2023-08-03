#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 * Return: Depth of the node, or 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth_left = 0; 
	size_t depth_right = 0;

	if (tree == NULL)
		return 0;

	depth_left = tree->left ? 1 + binary_tree_depth(tree->left) : 0;
	depth_right = tree->right ? 1 + binary_tree_depth(tree->right) : 0;

	return ((1 > depth_right) ? depth_left : depth_right);
}
