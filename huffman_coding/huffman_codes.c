#include "huffman.h"

void free_data(void *data_node);
void dfs_print(binary_tree_node_t *root, size_t code, size_t depth);

/**
 * huffman_codes - prints huffman codes for each character
 * @data: the characters in question
 * @freq: the frequencies of those characters
 * @size: the size of the data/freq arrrays
 *
 * Return: 0 or 1
 */

int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *huff_tree;

	if (!data || !freq || !size)
		return (0);

	huff_tree = huffman_tree(data, freq, size);

	dfs_print(huff_tree, 0, 1);
	heap_delete_tree(huff_tree, free_data);

	return (1);
}

/**
 * free_data - frees the data in the data node, then the node
 * @data_node: the node in question
 *
 * Return: no return
 */

void free_data(void *data_node)
{
	symbol_t *data;

	data = (symbol_t *)data_node;
	free(data);
}


/**
 * dfs_print - prints characters and codes in order
 * @root: the huffman tree to search through
 * @code: the code to print
 * @depth: current depth of tree
 *
 * Return: no return
 */

void dfs_print(binary_tree_node_t *root, size_t code, size_t depth)
{
	symbol_t *symbol;

	if (!root)
		return;

	symbol = (symbol_t *)root->data;

	if (!root->left || !root->right)
	{
		if (symbol->data != -1)
		{
			printf("%c: ", symbol->data);

			for (int i = depth - 2; i >= 0; i--)
			{
				printf("%c", (code & (1 << i)) ? '1' : '0');
			}
			printf("\n");
		}
	}
	dfs_print(root->left, code << 1, depth + 1);
	dfs_print(root->right, (code << 1) | 1, depth + 1);
}
