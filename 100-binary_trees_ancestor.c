#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
	binary_tree_t *ancestor_first, *ancestor_second;

	if (first == NULL || second == NULL)
		return (NULL);
	
	if (first == second)
		return ((binary_tree_t *)first);
	
	if (first->parent == NULL || second->parent == NULL)
		return (NULL);
	
	ancestor_first = first->parent;
	ancestor_second = second->parent;
	if (ancestor_first == ancestor_second)
		return (ancestor_first);

	return (binary_trees_ancestor(ancestor_first, ancestor_second));
}
