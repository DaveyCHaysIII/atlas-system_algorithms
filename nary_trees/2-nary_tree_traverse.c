#include "nary_trees.h"


size_t nary_recurse(nary_tree_t const *root,
		  size_t current_depth,
		  void (*action)(nary_tree_t const *node, size_t depth));
/**
 * nary_tree_traverse - traverses an nary tree
 * @root: the root of the tree
 * @action: action to take at every node
 *
 * Return: lowest size_t depth of tree
 */

size_t nary_tree_traverse(nary_tree_t const *root,
			  void (*action)(nary_tree_t const *node, size_t depth))
{
	if (!root || !action)
		return (0);

	size_t depth;

	depth = nary_recurse(root, 0, action);

	return (depth);
}

/**
 * nary_recurse - helper function for traverse
 * @root: the root of the tree
 * @current_depth: the current depth
 * @action: action to take at every node
 *
 * Return: current depth
 */

size_t nary_recurse(nary_tree_t const *root,
		  size_t current_depth,
		  void (*action)(nary_tree_t const *node, size_t depth))
{
	nary_tree_t *current, *temp;
	size_t tracker, i;

	action(root, current_depth);
	current = root->children;
	tracker = current_depth;
	i = 0;
	if (current != NULL)
		tracker++;
	while (current != NULL)
	{
		temp = current->next;
		i = nary_recurse(current, tracker, action);
		current = temp;
	}

	if (i > tracker)
		tracker = i;
	return (tracker);
}





