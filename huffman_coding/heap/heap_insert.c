#include "heap.h"

void bubble_up(heap_t *heap, binary_tree_node_t *current);

/**
 * heap_insert - inserts a binary_tree_t into a heap
 * @heap: the heap in question
 * @data: the data of the node
 *
 * Return: pointer to the new node
 */

binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node, *current;

	if (!heap || !data)
		return (NULL);

	new_node = binary_tree_node(NULL, data);
	if (!heap->root)
	{
		heap->root = new_node;
		heap->size++;
		return (new_node);
	}

	heap->size++;
	current = bfs_find(heap, 0);
	new_node->parent = current;
	if (current->left == NULL)
		current->left = new_node;
	else
		current->right = new_node;

	bubble_up(heap, new_node);
	return (new_node);
}

/**
 * bubble_up - fixes min HEAP from inserted node to root
 * @heap: the heap in question
 * @current: the node inserted
 *
 * Return: no return;
 */

void bubble_up(heap_t *heap, binary_tree_node_t *current)
{
	void *temp;

	if (!heap || !current || !current->parent)
		return;
	if (current == heap->root)
		return;

	while (current->parent &&
	       heap->data_cmp(current->data, current->parent->data) < 0)
	{
		temp = current->data;
		current->data = current->parent->data;
		current->parent->data = temp;
		current = current->parent;
	}
}
