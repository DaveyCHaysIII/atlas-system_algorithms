#include "nary_trees.h"

/**
 * path_exists - determines if a path exists in an nary tree
 * @root: the tree in question
 * @path: the path in question
 *
 * Return: 0 or 1
 */

int path_exists(nary_tree_t const *root, char const * const *path)
{
	if (!root || !path || !path[0])
		return (0);

	const nary_tree_t *current = root, *child;
	size_t i = 0;

	if (strcmp(root->content, path[0]) != 0)
		return (0);
	i++;

	while (path[i])
	{
		child = current->children;

		while (child && strcmp(child->content, path[i]) != 0)
			child = child->next;

		if (!child)
			return (0);

		current = child;
		i++;
	}
	return (1);
}
