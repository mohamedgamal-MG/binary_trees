#include "binary_trees.h"

/**
 * bst_find_minimum - Finds the node containing the minimum value in a BST.
 * @node: Pointer to the root node of the BST.
 * Return: Pointer to the node containing the minimum value.
 */
bst_t *bst_find_minimum(bst_t *node)
{
    while (node && node->left)
        node = node->left;
    return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 * Return: Pointer to the new root node of the tree after removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (!root)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else {
        if (!root->left) {
            bst_t *temp = root->right;
            free(root);
            return (temp);
        } else if (!root->right) {
            bst_t *temp = root->left;
            free(root);
            return (temp);
        }

        bst_t *temp = bst_find_minimum(root->right);
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }

    return (root);
}
