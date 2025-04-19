#include "nary_trees.h"

/**
 * nary_tree_delete - deletes a tree
 * @tree: the tree to delete
 *
 * Return: no return
 */

void nary_tree_delete(nary_tree_t *tree)
{
	if (!tree)
		return;

	nary_tree_t *current, *temp;

	current = tree->children;
	while (current != NULL)
	{
		temp = current->next;
		nary_tree_delete(current);
		current = temp;
	}
	free(tree->content);
	free(tree);
}
