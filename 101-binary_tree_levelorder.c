#include "binary_trees.h"

/**
 * binary_tree_levelorder - Perform a level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	{
		binary_tree_t *queue[100];  // Using a queue for BFS
		int front = 0, rear = 0;

		queue[rear++] = (binary_tree_t *)tree;

		while (front < rear)
		{
			binary_tree_t *current = queue[front++];
			func(current->n);
			
			if (current->left != NULL)
				queue[rear++] = current->left;

			if (current->right != NULL)
				queue[rear++] = current->right;
		}
	}
}
