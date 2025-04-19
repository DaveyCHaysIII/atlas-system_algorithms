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
	if (!root || !path)
		return (0);

	nary_tree_t *current;
	size_t i;

	current = root->children;
	i = 0;
	while (current != NULL)
	{
		if (path[i] == NULL)
			return (1);
		if (strcmp(current->content, path[i]) == 1)
		{
			current = current->children;
			i++;
			continue;
		}
		current = current->next;
	}
	return (0);
}
