#include "nary_trees.h"

size_t dia(nary_tree_t const *root, size_t *diameter);

/**
 * nary_tree_diameter - gives the diameter of a nary tree
 * @root: root of the nary tree
 *
 * Return: the diameter of the nary tree
 */

size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter;

	diameter = 0;
	dia(root, &diameter);
	return (diameter + 1);
}

/**
 * dia - recursive helper function for nary_tree_diameter
 * @root: the root of the tree in question
 * @diameter: pointer to the global diameter
 * Return: the diameter of the tree
 */

size_t dia(nary_tree_t const *root, size_t *diameter)
{
	if (!root)
		return (0);

	size_t max1 = 0, max2 = 0, h;
	nary_tree_t *current;

	for (current = root->children; current; current = current->next)
	{
		h = dia(current, diameter);
		if (h > max1)
		{
			max2 = max1;
			max1 = h;
		}
		else if (h > max2)
			max2 = h;
	}

	if (max1 + max2 > *diameter)
		*diameter = max1 + max2;

	return (1 + max1);
}

