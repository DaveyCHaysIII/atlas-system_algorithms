#include "heap.h"

void heap_delete_tree(binary_tree_node_t *root, void (*free_data)(void *));

/**
 * heap_delete - deletes a heap
 * @heap: the heap in question
 * @free_data: the function pointer responsible for freeing heap->node->data
 *
 * Return: no return
 */

void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	heap_delete_tree(heap->root, free_data);
	free(heap);
}

/**
 * heap_delete_tree - recursive postorder DFS to delete tree
 * @root: the root of the tree to delete
 * @free_data: if not null, frees the data
 *
 * Return: no return
 */

void heap_delete_tree(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (root)
	{
		if (root->left)
			heap_delete_tree(root->left, free_data);
		if (root->right)
			heap_delete_tree(root->right, free_data);
		if (free_data)
			free_data(root->data);
		free(root);
	}
}
