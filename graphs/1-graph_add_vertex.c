#include "graphs.h"

/**
 * graph_add_vertex - adds a vertex to the graph->vertices linked list
 * @graph: the graph in question
 * @str: the content to save in the vertex
 *
 * Return: pointer to new vertex
 */

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_vertex, *current;

	if (!str)
		return (NULL);
	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
		return (NULL);

	new_vertex->content = strdup(str);
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;
	new_vertex->next = NULL;

	graph->nb_vertices++;
	if (graph->vertices == NULL)
	{
		new_vertex->index = 0;
		graph->vertices = new_vertex;
		return (new_vertex);
	}
	for (current = graph->vertices;; current = current->next)
	{
		if (strcmp(current->content, str) == 0)
		{
			free(new_vertex->content);
			free(new_vertex);
			return (NULL);
		}
		if (current->next == NULL)
			break;
	}

	new_vertex->index = current->index + 1;
	current->next = new_vertex;

	return (new_vertex);
}
