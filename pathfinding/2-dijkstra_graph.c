#include "pathfinding.h"
#include <limits.h>

void find_dijk(graph_t *graph,
	       vertex_t const *start,
	       vertex_t const *target,
	       int *dist,
	       int *visited,
	       vertex_t **prev);
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

	queue_t *q = NULL;
	vertex_t *vcurrent;
	int *visited = calloc(graph->nb_vertices, sizeof(int));
	int *dist = malloc(graph->nb_vertices * sizeof(int));
	vertex_t **prev = malloc(sizeof(vertex_t *) * graph->nb_vertices);

	if (!visited || !dist || !prev)
		return (NULL);

	for (size_t i = 0; i < graph->nb_vertices; i++)
	{
		dist[i] = INT_MAX;
		prev[i] = NULL;
	}
	dist[start->index] = 0;

	find_dijk(graph, start, target, dist, visited, prev);

	q = queue_create();
	for (vcurrent = (vertex_t *)target;
	     vcurrent && vcurrent != start;
	     vcurrent = prev[vcurrent->index])
		queue_push_front(q, strdup(vcurrent->content));
	if (vcurrent == start)
		queue_push_front(q, strdup(start->content));
	free(visited);
	free(dist);
	free(prev);
	return (q);
}

/**
 * find_dijk - function to explore the graph
 * @graph: the graph
 * @start: the starting location in the graph
 * @target: where we're going
 * @dist: the distance array
 * @visited: the visited array
 * @prev: the array holding our trail
 *
 * Return: no return
 */

void find_dijk(graph_t *graph,
	       vertex_t const *start,
	       vertex_t const *target,
	       int *dist,
	       int *visited,
	       vertex_t **prev)
{
	while (1)
	{
		int min = INT_MAX, alt = 0;
		vertex_t *vcurrent = NULL, *dest = NULL, *vert = NULL;
		edge_t *e = NULL;

		/* searches for shortest path vertex */
		for (vert = graph->vertices; vert != NULL; vert = vert->next)
		{
			if (!visited[vert->index] && dist[vert->index] < min)
			{
				min = dist[vert->index];
				vcurrent = vert;
			}
		}

		printf("Checking %s, distance from %s is %d\n",
			vcurrent->content,
			start->content,
			min);

		if (!vcurrent || vcurrent == target)
			break;

		/* updates, assigns weights to dist, prev*/
		visited[vcurrent->index] = 1;
		for (e = vcurrent->edges; e; e = e->next)
		{
			dest = e->dest;
			alt = dist[vcurrent->index] + e->weight;

			if (alt < dist[dest->index])
			{
				dist[dest->index] = alt;
				prev[dest->index] = vcurrent;
			}
		}
	}
}
