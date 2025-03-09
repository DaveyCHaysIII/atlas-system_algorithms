#include "rb_trees.h"

/**
 * rb_tree_node - inserts a new node into an RB tree
 * @parent: pointer to the parent of the new node
 * @value: the value (node->n)
 * @color: the color of the new node
 *
 * Return: pointer to the new node
 *
 */

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_node = malloc(sizeof(rb_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->color = color;

	return (new_node);
}
