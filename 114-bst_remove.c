#include "binary_trees.h"

/**
 * get_min_successor - Get the minimum value node in the right subtree.
 * @node: The tree to check.
 * Return: The minimum value of this tree.
 */
int get_min_successor(bst_t *node)
{
    int left_min = 0;
    if (node == NULL)
    {
        return (0);
    }
    else
    {
        left_min = get_min_successor(node->left);
        if (left_min == 0)
        {
            return (node->n);
        }
        return (left_min);
    }
}

/**
 * replace_with_successor - Function that gets the next successor using the min
 * value in the right subtree, and then replaces the node value for
 * this successor.
 * @root: Node that has two children.
 * Return: The value found.
 */
int replace_with_successor(bst_t *root)
{
    int new_value = 0;
    new_value = get_min_successor(root->right);
    root->n = new_value;
    return (new_value);
}

/**
 * remove_node - Function that removes a node depending on its children.
 * @node: Node to remove.
 * Return: 0 if it has no children or other value if it has.
 */
int remove_node(bst_t *node)
{
    if (!node->left && !node->right)
    {
        if (node->parent && node->parent->right == node)
            node->parent->right = NULL;
        else if (node->parent)
            node->parent->left = NULL;
        free(node);
        return (0);
    }
    else if ((!node->left && node->right) || (!node->right && node->left))
    {
        if (!node->left)
        {
            if (node->parent && node->parent->right == node)
                node->parent->right = node->right;
            else if (node->parent)
                node->parent->left = node->right;
            node->right->parent = node->parent;
        }
        if (!node->right)
        {
            if (node->parent && node->parent->right == node)
                node->parent->right = node->left;
            else if (node->parent)
                node->parent->left = node->left;
            node->left->parent = node->parent;
        }
        free(node);
        return (0);
    }
    else
        return (replace_with_successor(node));
}

/**
 * bst_remove - Remove a node from a BST tree.
 * @root: Root of the tree.
 * @value: Node with this value to remove.
 * Return: The tree changed.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
    {
        return (NULL);
    }
    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else if (value == root->n)
    {
        int node_value = remove_node(root);
        if (node_value != 0)
            root->right = bst_remove(root->right, node_value);
    }
    return (root);
}
