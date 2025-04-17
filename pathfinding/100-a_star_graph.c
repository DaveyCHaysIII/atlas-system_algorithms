#include "pathfinding.h"
#include <limits.h>
#include <math.h>

void find_a_star(graph_t *graph,
	       vertex_t const *target,
	       int *dist,
	       int *visited,
	       vertex_t **prev,
	       int *score);

int heuristic(const vertex_t *a, const vertex_t *b);

/**
 * a_star_graph - the a* traversal of a graph
 * @graph: the graph to traverse
 * @start: the starting node
 * @target: the target node
 *
 * Return: the queue from start to target
 */

queue_t *a_star_graph(graph_t *graph,
		vertex_t const *start,
		vertex_t const *target)
{
	if (!graph || !start || !target)
		return (NULL);

	queue_t *q = NULL;
	vertex_t *vcurrent;
	int *visited = calloc(graph->nb_vertices, sizeof(int));
	int *dist = malloc(graph->nb_vertices * sizeof(int));
	int *score = malloc(graph->nb_vertices * sizeof(int));
	vertex_t **prev = malloc(sizeof(vertex_t *) * graph->nb_vertices);

	if (!visited || !dist || !prev)
		return (NULL);
	for (size_t i = 0; i < graph->nb_vertices; i++)
	{
		dist[i] = INT_MAX;
		score[i] = INT_MAX;
		prev[i] = NULL;
	}
	dist[start->index] = 0;
	score[start->index] = heuristic(start, target);
	find_a_star(graph, target, dist, visited, prev, score);
	if (prev[target->index] == NULL)
	{
		free(visited);
		free(dist);
		free(prev);
		return (NULL);
	}
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
	free(score);
	return (q);
}


/**
 * find_a_star - function to explore the graph
 * @graph: the graph
 * @target: where we're going
 * @dist: the distance array
 * @visited: the visited array
 * @prev: the array holding our trail
 * @score: the arrray holding our score
 *
 * Return: no return
 */

void find_a_star(graph_t *graph,
	       vertex_t const *target,
	       int *dist,
	       int *visited,
	       vertex_t **prev,
	       int *score)
{
	while (1)
	{
		int min = INT_MAX, alt = 0, est = 0;
		vertex_t *vcurrent = NULL, *dest = NULL, *vert = NULL;
		edge_t *e = NULL;

		/* searches for shortest path vertex */
		for (vert = graph->vertices; vert != NULL; vert = vert->next)
		{
			if (!visited[vert->index] && score[vert->index] < min)
			{
				min = score[vert->index];
				vcurrent = vert;
			}
		}
		if (!vcurrent)
			break;
		printf("Checking %s, distance to %s is %d\n",
			vcurrent->content,
			target->content,
			heuristic(vcurrent, target));
		if (vcurrent == target)
			break;

		/* updates, assigns weights to dist, prev*/
		visited[vcurrent->index] = 1;
		for (e = vcurrent->edges; e; e = e->next)
		{
			dest = e->dest;
			alt = dist[vcurrent->index] + e->weight;
			est = alt + heuristic(dest, target);

			if (score[dest->index] == -1 || est < score[dest->index])
			{
				dist[dest->index] = alt;
				score[dest->index] = est;
				prev[dest->index] = vcurrent;
			}
		}
	}
}

/**
 * heuristic - a function to give the manhattan distance to target
 * @a: the current node we're checking
 * @b: the target node
 *
 * Return: the manhattan distance or 0
 */

int heuristic(const vertex_t *a, const vertex_t *b)
{
	if (!a || !b)
		return (0);

	int dx = a->x - b->x;
	int dy = a->y - b->y;

	return ((int)sqrt(dx * dx + dy * dy));
}
