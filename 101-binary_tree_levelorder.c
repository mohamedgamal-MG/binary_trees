#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;
    
    if (tree == NULL)
    {
        return (0);
    }
    else
    {
        if (tree)
        {
            left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
            right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
        }
        return ((left_height > right_height) ? left_height : right_height);
    }
}

/**
 * binary_tree_depth - depth of specified node from root
 * @tree: node to check the depth
 * Return: 0 is it is the root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - this function makes a linked list from depth level and node
 * @head: pointer to head of linked list
 * @tree: node to store
 * @level: depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
    link_t *new_node, *aux;
    
    new_node = malloc(sizeof(link_t));
    if (new_node == NULL)
    {
        return;
    }
    new_node->n = level;
    new_node->node = tree;
    
    if (*head == NULL)
    {
        new_node->next = NULL;
        *head = new_node;
    }
    else
    {
        aux = *head;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        new_node->next = NULL;
        aux->next = new_node;
    }
}

/**
 * recursion - goes through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: Nothing by default it affects the pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
    size_t node_level = 0;
    
    if (tree != NULL)
    {
        node_level = binary_tree_depth(tree);
        linked_node(head, tree, node_level);
        recursion(head, tree->left);
        recursion(head, tree->right);
    }
}

/**
 * binary_tree_levelorder - print the nodes element in a lever-order
 * @tree: root node
 * @func: function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    link_t *head, *aux;
    size_t tree_height = 0, current_level = 0;
    
    if (!tree || !func)
    {
        return;
    }
    else
    {
        tree_height = binary_tree_height(tree);
        head = NULL;
        recursion(&head, tree);
        
        while (current_level <= tree_height)
        {
            aux = head;
            while (aux != NULL)
            {
                if (current_level == aux->n)
                {
                    func(aux->node->n);
                }
                aux = aux->next;
            }
            current_level++;
        }
        
        while (head != NULL)
        {
            aux = head;
            head = head->next;
            free(aux);
        }
    }
}
