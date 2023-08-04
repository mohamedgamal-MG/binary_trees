#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int balance_factor;

    if (tree == NULL)
        return (0);

    balance_factor = binary_tree_balance(tree);
    if (balance_factor > 1 || balance_factor < -1)
        return (0);

    if (abs(binary_tree_height(tree->left) - binary_tree_height(tree->right)) > 1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}
