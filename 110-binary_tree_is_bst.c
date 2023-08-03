#include "binary_trees.h"

/**
 * check_bst - Helper function to check if a binary tree is a valid BST.
 * @tree: The root node of the tree.
 * @prev: A pointer to the previously visited node.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int check_bst(const binary_tree_t *tree, const binary_tree_t **prev)
{
    if (tree == NULL)
        return (1);

    if (!check_bst(tree->left, prev))
        return (0);

    if (*prev != NULL && tree->n <= (*prev)->n)
        return (0);

    *prev = tree;

    return (check_bst(tree->right, prev));
}

/**
 * binary_tree_is_bst - Function that checks if a binary tree is a valid BST.
 * @tree: The root node of the tree.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    const binary_tree_t *prev = NULL;
    return (check_bst(tree, &prev));
}
