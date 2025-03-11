#include "rb_trees.h"


rb_tree_t *bst_insert(rb_tree_t **tree, int value);
void tree_fix(rb_tree_t **tree, rb_tree_t *node);

/**
 * rb_tree_insert - inserts a node into a tree
 * @tree: the node in question
 * @value: the value of the node to insert
 *
 * Return: a pointer to the new node
 */

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *node = bst_insert(tree, value);

	if (node == NULL)
		return (NULL);

	tree_fix(tree, node);
	return (node);
}

/**
 * bst_insert - insert an rb node like a bst
 * @tree: the tree to insert into
 * @value: the value of the node to create
 *
 * Return: the address of the new node
 */

rb_tree_t *bst_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new_node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
		return (*tree = rb_tree_node(NULL, value, RED));
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			return ((*tree)->left = new_node);
		}
		return (bst_insert(&(*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			return ((*tree)->right = new_node);
		}
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL);
}

/**
 * tree_fix - fixes the tree
 * @tree: the tree in question
 * @node: the node in question
 *
 * Return: no return
 */

void tree_fix(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *uncle;

	if (!node)
		return;
	if (node->parent == NULL)
	{
		node->color = BLACK;
		return;
	}
	if (node->parent == BLACK)
		return;

	uncle = find_uncle(node);
	if (!uncle)
}
