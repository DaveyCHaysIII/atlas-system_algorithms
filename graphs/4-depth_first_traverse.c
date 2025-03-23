#include "graphs.h"


size_t dfs(vertex_t *start,
	    void (*action)(const vertex_t *v, size_t depth),
	    size_t d,
	    size_t *visited);
/**
 * depth_first_traverse - traverse a graph depth first!
 * @graph: the graph in question
 * @action: the action to perform on each vertex
 *
 * Return: the biggest vertex depth (number of depths)
 */

size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	size_t *visited, max_depth;

	visited = malloc(sizeof(size_t) * (graph->nb_vertices));
	if (!visited || !graph || !action || !graph->vertices)
		return (0);
	memset(visited, 0, (sizeof(size_t) * (graph->nb_vertices)));

	max_depth = dfs(graph->vertices, action, 0, visited);
	free(visited);

	return (max_depth);
}

/**
 * dfs - recursive depth first search algorithm
 * @start: the starting vertex
 * @action: function pointer for every vertex
 * @d: the current depth
 * @visited: the visited array
 *
 * Return: depth
 */

size_t dfs(vertex_t *start,
	    void (*action)(const vertex_t *v, size_t depth),
	    size_t d,
	    size_t *visited)
{
	edge_t *current;
	size_t max_depth, child_depth;

	visited[start->index] = 1;
	action(start, d);

	max_depth = d;
	current = start->edges;
	while (current != NULL)
	{
		if (!visited[current->dest->index])
		{
			child_depth = dfs(current->dest,
					action,
					(d + 1),
					visited);
			if (child_depth > max_depth)
				max_depth = child_depth;
		}
		current = current->next;
	}
	return (max_depth);
}
