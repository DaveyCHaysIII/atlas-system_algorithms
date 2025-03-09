#include "rb_trees.h"


void inorder(const rb_tree_t *tree, void (*func)(int, int *, int *),
		int *store, int *flag);
int check_red_adjacent(const rb_tree_t *tree)
void check_sorted(int val, int *store, int *flag);

/**
 * rb_tree_is_valid - checks if a binary tree is valid
 * @tree: the tree in question
 *
 * Description: The tree has to follow several rules
 * 1. The tree must be a BST
 * 2. Every node is either red or black
 * 3. The root node must be black
 * 4. There are no two adjacent red nodes
 * 5. Every path from root to a NULL node has the
 * same number of black nodes
 * the flag variable only changes from 1 to 0, so
 * any stage that changes it to 0 invalidates the tree
 *
 * Return: 1 for valid, 0 for invalid
 *
 */

int rb_tree_is_valid(const rb_tree_t *tree)
{
	int val_stored, flag;

	if (tree == NULL)
		return (0);
	if (tree->color != BLACK) /* Check for Case 3 */
		return (0);

	int flag = 1;
	int val_stored = 0;

	inorder(tree, check_sorted, &store, &flag);

	return (flag);
}


/**
 * inorder()- navigates a tree in order
 * @tree: the tree in question
 * @func: the function to perform on the tree
 * @store: the stored value of the previous tree->n
 * @flag: the 0-1 flag determening if the bst is a bst
 *
 * Return: we don' need no stinkin' returns
 */

void inorder(const rb_tree_t *tree,
		void (*func)(int, int *, int *), int *val_stored, int *flag)
{
	if (tree && func)
	{
		if (tree->color != BLACK && tree->color !== RED)
		{
			*flag = 0;
			return; /* Check for Case 2 */
		}
		else if (tree->color == RED && check_red_adjacent(tree) == 1)
		{
			*flag = 0;
			return; /* Check for Case 4 */

		}
		if (*flag && tree->left)
			inorder(tree->left, func, val_stored, flag);

		func(tree->n, val_stored, flag);

		if (*flag && tree->right)
			inorder(tree->right, func, val_stored, flag);
	}
}

/**
 * check_red_adjacent - checks if node has red adjacency
 * @tree: the node in question
 *
 * Return: 1 if adjacency, 0 if not
 */

int check_red_adjacent(const rb_tree_t *tree)
{
	if (!tree)
		return 0;

	if ((tree->parent && tree->parent->color == RED) ||
		(tree->left && tree->left->color == RED) ||
		(tree->right && tree->right->color == RED))
	{
		return (1);
	}
	return (0);
}


/**
 * check_sorted - checks a value in a store
 * @val: the number to check
 * @store: the store
 * @flag: the 0-1 flag determening if the bst is a bst
 * Return: no return
 */

void check_sorted(int val, int *store, int *flag)
{
	if (val <= *store) /* Check for Case 1 */
	{
		*flag = 0;
		return;
	}
	*store = val;
}
