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
	queue_t *q;

	if (!heap || !data)
		return (NULL);

	new_node = binary_tree_node(NULL, data);
	if (!heap->root)
	{
		heap->root = new_node;
		heap->size++;
		return (new_node);
	}
	q = create_queue();
	enqueue(q, heap->root);
	while (q->front != NULL)
	{
		current = (binary_tree_node_t *)dequeue(q);
		if (current->left == NULL)
		{
			heap->size++;
			current->left = new_node;
			new_node->parent = current;
			free_queue(q);
			bubble_up(heap, new_node);
			return (new_node);
		}
		else if (current->right == NULL)
		{
			heap->size++;
			current->right = new_node;
			new_node->parent = current;
			free_queue(q);
			bubble_up(heap, new_node);
			return (new_node);
		}
		enqueue(q, current->left);
		enqueue(q, current->right);
	}
	return (NULL);
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

	while (current->parent &&
	       heap->data_cmp(current->data, current->parent->data) < 0)
	{
		temp = current->data;
		current->data = current->parent->data;
		current->parent->data = temp;
		current = current->parent;
	}
}
