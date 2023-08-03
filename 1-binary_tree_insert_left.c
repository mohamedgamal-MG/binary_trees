#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insert a node as the laft-child of another node.
 * @parent: A pointer to the parent node.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}
