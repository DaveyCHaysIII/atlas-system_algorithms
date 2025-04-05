#include "huffman.h"

/**
 * huffman_tree - creates a huffman tree from data
 * @data: the character to add
 * @freq: the frequency of that character
 * @size: the size of the arrays
 *
 * Return: the huffman tree, or NULL
 */

binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *priority_queue;
	binary_tree_node_t *huffman_root;

	priority_queue = huffman_priority_queue(data, freq, size);
	if (!priority_queue || priority_queue->size < 2)
		return (NULL);

	while (priority_queue->size > 1)
		huffman_extract_and_insert(priority_queue);

	huffman_root = (binary_tree_node_t *)(priority_queue->root->data);
	return (huffman_root);
}
