#ifndef MAIN_HEAP
#define MAIN_HEAP

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

/**
 * struct queue_node - queue node data structure
 * @node: the binary tree node it holds
 * @next: the next binary tree node in line
 */
typedef struct queue_node
{
	const binary_tree_node_t *node;
	struct queue_node *next;
} queue_node_t;

/**
 * struct queue - queue data structure
 * @front: the front node of the queue
 * @rear: the rear node of the data structure
 */
typedef struct queue
{
	queue_node_t *front, *rear;
} queue_t;

/* primary functions */
heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void *heap_extract(heap_t *heap);

/* heap_utils */
queue_t *create_queue(void);
void free_queue(queue_t *q);
void enqueue(queue_t *q, const binary_tree_node_t *node);
const binary_tree_node_t *dequeue(queue_t *q);
/*bubble_up*/
/*bubble_down*/

#endif
