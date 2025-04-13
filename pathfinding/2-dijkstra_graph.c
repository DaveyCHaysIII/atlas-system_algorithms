#include "pathfinding.h"
#include <limits.h>

/**
 * dijkstra_graph - the dijkstra traversal of a graph
 * @graph: the graph to traverse
 * @start: the starting vertex
 * @target: the target vertex
 *
 * Return: the queue of the path from start to target
 */

queue_t *dijkstra_graph(graph_t *graph,
			vertex_t const *start,
			vertex_t const *target)
{

	if (!graph || !start || !target)
		return (NULL);

	int *visited = calloc(graph->nb_vertices, sizeof(int));
	int *dist = malloc(graph->nb_vertices * sizeof(int));
	int **prev = malloc(sizeof(vertex_t *) * graph->nb_vertices);

	if (!visited || !dist || !prev)
		return (NULL);

	for (size_t i = 0; i < graph->nb_vertices; i++)
	{
		dist[i] = INT_MAX;
		prev[i] = NULL;
	}
	dist[start->index] = 0;




}
