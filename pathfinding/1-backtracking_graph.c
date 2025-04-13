#include "pathfinding.h"

int btg_recurse(int *visited,
		 queue_t *q,
		 graph_t *graph,
		 vertex_t *vcurrent,
		 vertex_t *target);
/**
 * backtracking_graph - backtracking algo for traversing a graph
 * @graph: the graph to traverse
 * @start: the starting vertex
 * @target: the target vertex
 *
 * Return: the queue containing the path from start to target
 */

queue_t *backtracking_graph(graph_t *graph,
			    vertex_t const *start,
			    vertex_t const *target)
{

	int *visited;
	queue_t *new_queue;

	if (!graph || !start || !target)
		return (NULL);

	visited = calloc(graph->nb_vertices, sizeof(int));
	if (!visited)
		return (NULL);
	new_queue = queue_create();
	if (!new_queue)
	{
		free(visited);
		return (NULL);
	}
	if (!btg_recurse(visited,
			 new_queue,
			 graph,
			 (vertex_t *)start,
			 (vertex_t *)target))
	{
		free(visited);
		queue_delete(new_queue);
		return (NULL);
	}
	free(visited);
	return (new_queue);
}

/**
 * btg_recurse - recurse through graph
 * @visited: the visited array
 * @q: the queue
 * @graph: the graph to traverse
 * @vcurrent: the current vertice
 * @target: the target vertice
 *
 * Return: 1 or 0
 */

int btg_recurse(int *visited,
		 queue_t *q,
		 graph_t *graph,
		 vertex_t *vcurrent,
		 vertex_t *target)
{
	edge_t *ecurrent;

	if (!vcurrent || visited[vcurrent->index])
		return (0);
	visited[vcurrent->index] = 1;
	printf("Checking %s\n", vcurrent->content);

	if (vcurrent == target)
	{
		queue_push_front(q, strdup(vcurrent->content));
		return (1);
	}
	ecurrent = vcurrent->edges;
	while (ecurrent != NULL)
	{
		if (btg_recurse(visited, q, graph, ecurrent->dest, target))
		{
			queue_push_front(q, strdup(vcurrent->content));
			return (1);
		}
		ecurrent = ecurrent->next;
	}
	return (0);
}
