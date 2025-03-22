#include "graphs.h"

/**
 * graph_delete - deletes a graph
 * @graph: the graph in question
 *
 * Return: no return
 */

void graph_delete(graph_t *graph)
{
	vertex_t *vcurrent, *vnext;
	edge_t *ecurrent, *enext;

	if (!graph)
		return;
	if (graph->vertices == NULL)
	{
		free(graph);
		return;
	}
	for (vcurrent = graph->vertices; vcurrent != NULL;)
	{
		vnext = vcurrent->next;
		if (vcurrent->edges != NULL)
		{
			for (ecurrent = vcurrent->edges; ecurrent != NULL;)
			{
				enext = ecurrent->next;
				free(ecurrent);
				ecurrent = enext;
			}
		}
		free(vcurrent->content);
		free(vcurrent);
		vcurrent = vnext;
	}
	free(graph);
}
