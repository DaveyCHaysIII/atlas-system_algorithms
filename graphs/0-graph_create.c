#include "graphs.h"

/**
 * graph_create - creates a new graph
 *
 * Return: no return
 */
graph_t *graph_create(void)
{
	graph_t *new_graph;

	new_graph = malloc(sizeof(graph_t));
	if (!new_graph)
		exit(EXIT_FAILURE);

	new_graph->nb_vertices = 0;
	new_graph->vertices = NULL;

	return (new_graph);
}
