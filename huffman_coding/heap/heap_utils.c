#include "heap.h"

/**
 * create_queue - create a queue
 *
 * Return: the queue
 */

queue_t *create_queue(void)
{
	queue_t *q;

	q = malloc(sizeof(queue_t));
	q->front = q->rear = NULL;
	return (q);
}

/**
 * free_queue - frees a queue
 * @q: the queue to free
 *
 * Return: no return
 */

void free_queue(queue_t *q)
{
	while (dequeue(q) != NULL)
		;

	free(q);
}

/**
 * enqueue - enqueue's a thing
 * @q: the queue
 * @node: the binary tree node to enqueue
 *
 * Return: no return
 */

void enqueue(queue_t *q, const binary_tree_node_t *node)
{

	queue_node_t *new_node;

	if (!node)
		return;
	new_node = malloc(sizeof(queue_node_t));
	new_node->node = node;
	new_node->next = NULL;

	if (!q->rear)
		q->front = q->rear = new_node;
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
}

/**
 * dequeue - dequeue's a thing
 * @q: the queue in question
 *
 * Return: a new binary_tree_node_t
 */

const binary_tree_node_t *dequeue(queue_t *q)
{

	queue_node_t *temp;
	const binary_tree_node_t *node;

	if (!q->front)
		return (NULL);
	temp = q->front;
	node = temp->node;
	q->front = q->front->next;

	if (!q->front)
		q->rear = NULL;

	free(temp);
	return (node);
}

