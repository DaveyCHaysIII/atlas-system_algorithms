#include "heap.h"

/**
 * binary_tree_node - creates a node for the binary tree (heap)
 * @parent: pointer to the parent node
 * @data: data the node is carrying
 *
 * Return: pointer to the newly created node
 */

binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node;

	if (!data)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_node_t));
	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->data = data;

	return (new_node);
}
