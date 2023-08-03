#include "binary_trees.h"

/**
 * create_new_node - Function that creates a new node in a linked list
 * @node: Pointer to the node to be created
 * Return: The newly created node
 */
link_t *create_new_node(binary_tree_t *node)
{
    link_t *new_node;
    new_node = malloc(sizeof(link_t));
    if (new_node == NULL)
    {
        return (NULL);
    }
    new_node->node = node;
    new_node->next = NULL;
    return (new_node);
}

/**
 * free_queue - Function that frees the nodes in the linked list
 * @head: The head node of the linked list
 */
void free_queue(link_t *head)
{
    link_t *temp_node;
    while (head)
    {
        temp_node = head->next;
        free(head);
        head = temp_node;
    }
}

/**
 * push - Function that pushes a node into the queue
 * @node: Pointer to the node to be pushed
 * @head: The head node of the queue
 * @tail: The tail node of the queue
 */
void push(binary_tree_t *node, link_t *head, link_t **tail)
{
    link_t *new_node;
    new_node = create_new_node(node);
    if (new_node == NULL)
    {
        free_queue(head);
        exit(1);
    }
    (*tail)->next = new_node;
    *tail = new_node;
}

/**
 * pop - Function that pops a node from the queue
 * @head: The head node of the queue
 */
void pop(link_t **head)
{
    link_t *temp_node;
    temp_node = (*head)->next;
    free(*head);
    *head = temp_node;
}

/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    link_t *head, *tail;
    int flag = 0;
    if (tree == NULL)
    {
        return (0);
    }
    head = tail = create_new_node((binary_tree_t *)tree);
    if (head == NULL)
    {
        exit(1);
    }
    while (head != NULL)
    {
        if (head->node->left != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return (0);
            }
            push(head->node->left, head, &tail);
        }
        else
        {
            flag = 1;
        }
        if (head->node->right != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return (0);
            }
            push(head->node->right, head, &tail);
        }
        else
        {
            flag = 1;
        }
        pop(&head);
    }
    free_queue(head);
    return (1);
}

