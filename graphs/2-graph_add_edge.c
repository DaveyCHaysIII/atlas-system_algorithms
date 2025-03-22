#include "graphs.h"

int add_edge(vertex_t *src, vertex_t *dest);

/**
 * graph_add_edge - adds an edge to a vertex on a graph
 * @graph: the graph in question
 * @src: the source node to find
 * @dest: the dest node to find
 * @type: UNIDIRECTIONAL or BIDIRECTIONAL enum
 *
 * if (BIDIRECTIONAL), you have to add an edge to both vertex_t's
 *
 * Return: 1 on success, 0 on failure
 */

int graph_add_edge(graph_t *graph,
		   const char *src,
		   const char *dest,
		   edge_type_t type)
{
	vertex_t *vert_src, *vert_dest, *current;

	if (!graph || !graph->vertices || !src || !dest)
		return (0);
	vert_src = vert_dest = NULL;
	for (current = graph->vertices;; current = current->next)
	{
		if (!strcmp(current->content, src))
			vert_src = current;
		if (!strcmp(current->content, dest))
			vert_dest = current;
		if (current->next == NULL)
			break;
	}
	if (!vert_src || !vert_dest)
		return (0);
	if (!add_edge(vert_src, vert_dest))
		return (0);
	if (type == BIDIRECTIONAL)
	{
		if (!add_edge(vert_dest, vert_src))
			return (0);
	}
	return (1);
}

/**
 * add_edge - helper function for graph_add_edge
 * @src: the source edge
 * @dest: the dest edge
 *
 * directionality doesnt' matter, that's handled in graph_add_edge
 *
 * Return: 1 on success, 0 on fail
 */

int add_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *new_edge, *current;

	if (!src || !dest)
		return (0);
	new_edge = malloc(sizeof(edge_t));
	if (!new_edge)
		return (0);
	new_edge->dest = dest;
	new_edge->next = NULL;
	if (src->edges == NULL)
	{
		src->nb_edges++;
		src->edges = new_edge;
		return (1);
	}
	for (current = src->edges;
	     current->next != NULL;
	     current = current->next)
	{
		if (current->dest == dest)
		{
			free(new_edge);
			return (0);
		}
	}
	src->nb_edges++;
	current->next = new_edge;
	return (1);
}
