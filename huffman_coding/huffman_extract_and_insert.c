#include "huffman.h"

/**
 * huffman_extract_and_insert - extract roots insert into priority queue
 * @priority_queue: the priority queue in question
 *
 * Return: 1 (success) or 0 (failure)
 */

int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *new_symbol_node, *symbol_node_1, *symbol_node_2;
	symbol_t *new_symbol, *symbol_1, *symbol_2;
	size_t new_freq;

	if (!priority_queue || priority_queue->size < 2)
		return (0);

	symbol_node_1 = heap_extract(priority_queue);
	symbol_node_2 = heap_extract(priority_queue);
	symbol_1 = (symbol_t *)(symbol_node_1->data);
	symbol_2 = (symbol_t *)(symbol_node_2->data);

	new_freq = symbol_1->freq + symbol_2->freq;
	new_symbol = symbol_create(-1, new_freq);
	new_symbol_node = binary_tree_node(NULL, new_symbol);
	if (!new_symbol || !new_symbol_node)
		return (0);

	symbol_node_1->parent = symbol_node_2->parent = new_symbol_node;
	new_symbol_node->left = symbol_node_1;
	new_symbol_node->right = symbol_node_2;

	if (heap_insert(priority_queue, new_symbol_node) == NULL)
		return (0);
	return (1);
}
