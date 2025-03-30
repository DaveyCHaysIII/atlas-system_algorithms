#include "heap.h"

void bubble_down(heap_t *heap);

/**
 * heap_extract - 'pop' the top off the heap
 * @heap: the heap in question
 *
 * Return: data held in heap->root (void *)
 */

void *heap_extract(heap_t *heap)
{
	void *data;
	binary_tree_node_t *last_node;

	if (!heap || !heap->root)
		return (NULL);
	data = heap->root->data;
	if (heap->size == 1)
	{
		free(heap->root);
		heap->root = NULL;
		heap->size = 0;
		return (data);
	}
	last_node = bfs_find(heap, 1);
	if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;
	last_node->parent = NULL;
	last_node->left = heap->root->left;
	last_node->right = heap->root->right;

	if (last_node->left)
		last_node->left->parent = last_node;
	if (last_node->right)
		last_node->right->parent = last_node;

	free(heap->root);
	heap->root = last_node;
	heap->size--;
	bubble_down(heap);
	return (data);
}

/**
  * bubble_down - fixes root > children
  * @heap: the heap to fix
  *
  * Return: no return
  */

void bubble_down(heap_t *heap)
{
	binary_tree_node_t *current, *smallest;
	void *temp_data;

	if (!heap || !heap->root)
		return;

	current = heap->root;
	temp_data = NULL;
	while (current != NULL)
	{
		smallest = current;
		if (current->left &&
		   (heap->data_cmp(current->left->data, smallest->data) < 0))
			smallest = current->left;
		if (current->right &&
		   (heap->data_cmp(current->right->data, smallest->data) < 0))
			smallest = current->right;
		if (smallest == current)
			break;

		temp_data = current->data;
		current->data = smallest->data;
		smallest->data = temp_data;

		current = smallest;
	}
}
