#include "nary_trees.h"

/**
 * nary_tree_insert - create and insert a node into tree
 * @parent: the parent tree to insert into
 * @str: the content of the node
 *
 * Return: pointer to new node
 */

nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	if (!str)
		return (NULL);

	nary_tree_t *new_node, *temp;

	new_node = malloc(sizeof(nary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->content = (char *)str;
	new_node->parent = NULL;
	new_node->nb_children = 0;
	new_node->children = NULL;
	new_node->next = NULL;

	if (!parent)
		return (new_node);

	temp = parent->children;
	parent->nb_children++;
	parent->children = new_node;
	new_node->parent = parent;
	new_node->next = temp;

	return (new_node);
}
