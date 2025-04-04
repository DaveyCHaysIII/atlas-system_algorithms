#include "huffman.h"

int symbol_cmp(void *a, void *b);

/**
 * huffman_priority_queue - creates a priority queue in preparation for huffman
 * @data: the character array
 * @freq: the frequency array
 * @size: the size of the arrays
 *
 * Return: the newly made queue
 */

heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	if (!data || !freq || !size)
		return (NULL);

	heap_t *new_heap;
	binary_tree_node_t *new_node;
	symbol_t *new_symbol;
	size_t i;

	new_heap = heap_create(&symbol_cmp);
	if (!new_heap)
	{
		printf("no new heap\n");
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		new_symbol = symbol_create(data[i], freq[i]);
		new_node = binary_tree_node(NULL, new_symbol);
		heap_insert(new_heap, new_node);
		if (!new_heap->root)
			break;
	}
	return (new_heap);
}

/**
 * symbol_cmp - the function pointer
 * @a: the first void pointer
 * @b: the second void pointer
 *
 * Return: difference
 */

int symbol_cmp(void *a, void *b)
{
	symbol_t *symbol_a = (symbol_t *)(((binary_tree_node_t *)a)->data);
	symbol_t *symbol_b = (symbol_t *)(((binary_tree_node_t *)b)->data);

	return ((int)(symbol_a->freq - symbol_b->freq));
}
