#include "rb_trees.h"

rb_tree_t *bst_insert(rb_tree_t **tree, int value);
void tree_fix(rb_tree_t **tree, rb_tree_t *node);
rb_tree_t *find_uncle(rb_tree_t *node);
void rotate_fix(rb_tree_t **tree, rb_tree_t *node);
void right_rotate(rb_tree_t **tree, rb_tree_t *node);
void left_rotate(rb_tree_t **tree, rb_tree_t *node);

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
	(*tree)->color = BLACK;
	tree_fix(tree, node);
	(*tree)->color = BLACK;
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
			new_node = rb_tree_node(*tree, value, RED);
			return ((*tree)->left = new_node);
		}
		return (bst_insert(&(*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = rb_tree_node(*tree, value, RED);
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
	if (node == *tree)
	{
		node->color = BLACK;
		return;
	}
	if (node->parent->color == BLACK)
		return;

	uncle = find_uncle(node);
	if (uncle && uncle->color == RED)
	{
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		uncle->color = BLACK;
		tree_fix(tree, node->parent->parent);
	}
	else
		rotate_fix(tree, node);
}

/**
 * find_uncle - finds the uncle and returns it
 * @node: the node to investigate
 *
 * Return: pointer or NULL
 */

rb_tree_t *find_uncle(rb_tree_t *node)
{
	rb_tree_t *parent;

	if (!node || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	if (parent == parent->parent->left)
		return (parent->parent->right);
	return (parent->parent->left);
}

/**
 * rotate_fix - fixes the tree with rotatons
 * @tree: the tree in question
 * @node: the node in question
 *
 * Return: no return
 */

void rotate_fix(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *parent, *grandparent;

	parent = node->parent;
	if (parent == *tree)
		return;
	grandparent = node->parent->parent;

	if (parent == grandparent->left)
	{
		if (node == parent->right)
		{
			left_rotate(tree, parent);
			node = parent;
			parent = node->parent;
		}
		right_rotate(tree, grandparent);
		parent->color = BLACK;
		grandparent->color = RED;
	}
	else
	{
		if (node == parent->left)
		{
			right_rotate(tree, parent);
			node = parent;
			parent = node->parent;
		}
		left_rotate(tree, grandparent);
		parent->color = BLACK;
		grandparent->color = RED;
	}
	(*tree)->color = BLACK;
}

/**
 * right_rotate - rotates a tree to the right
 * @tree: the tree in question
 * @node: the specific node to pivot
 *
 * Return: no return
 */

void right_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *left_child;

	left_child = node->left;
	node->left = left_child->right;

	if (left_child->right)
		left_child->right->parent = node;
	left_child->parent = node->parent;
	if (!node->parent)
		*tree = left_child;
	else if (node == node->parent->right)
		node->parent->right = left_child;
	else
		node->parent->left = left_child;
	left_child->right = node;
	node->parent = left_child;
}


/**
 * left_rotate - rotates a tree to the left
 * @tree: the tree in question
 * @node: the specific node to pivot
 *
 * Return: no return
 */

void left_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *right_child;

	right_child = node->right;
	node->right = right_child->left;

	if (right_child->left)
		right_child->left->parent = node;
	right_child->parent = node->parent;
	if (!node->parent)
		*tree = right_child;
	else if (node == node->parent->left)
		node->parent->left = right_child;
	else
		node->parent->right = right_child;
	right_child->left = node;
	node->parent = right_child;
}
