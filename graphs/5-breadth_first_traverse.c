#include "graphs.h"

queue_t *init_queue(size_t size);
void enqueue(queue_t *q, vertex_t *vertex);
vertex_t *dequeue(queue_t *q);
void free_queue(queue_t *q);

/**
 * breadth_first_traverse - traverse a graph breadth first!
 * @graph: the graph in question
 * @action: the action to perform at each vert
 *
 * Return: the deepest depth
 */
size_t breadth_first_traverse(const graph_t *graph,
			      void (*action)(const vertex_t *v, size_t depth))
{
	vertex_t *current;
	edge_t *edge;
	size_t *visited, depth;
	queue_t *q;
	size_t level_nodes, next_level_nodes;

	if (!graph || !action || !graph->vertices)
		return (0);
	q = init_queue(graph->nb_vertices);
	visited = calloc(graph->nb_vertices, sizeof(size_t));
	depth = next_level_nodes = 0;
	current = graph->vertices;
	enqueue(q, current);
	visited[current->index] = level_nodes = 1;
	while (q->front != q->rear)
	{
		current = dequeue(q);
		action(current, depth);
		edge = current->edges;
		while (edge)
		{
			if (!visited[edge->dest->index])
			{
				enqueue(q, edge->dest);
				visited[edge->dest->index] = 1;
				next_level_nodes++;
			}
			edge = edge->next;
		}
		level_nodes--;
		if (level_nodes == 0 && next_level_nodes > 0)
		{
			depth++;
			level_nodes = next_level_nodes;
			next_level_nodes = 0;
		}
	}
	free_queue(q);
	free(visited);
	return (depth);
}

/**
 * init_queue - initialize a queue
 * @size: the size of the queue
 *
 * Return: pointer to initialized queue
 */
queue_t *init_queue(size_t size)
{
	queue_t *q;
	size_t qsize;

	qsize = (sizeof(vertex_t *) * size);
	q = malloc(sizeof(queue_t));
	q->arr = malloc(qsize);
	memset(q->arr, 0, qsize);
	q->front = 0;
	q->rear = 0;
	q->size = qsize;

	return (q);
}

/**
 * enqueue - enqueue's an index to the queue
 * @q: the queue in question
 * @vertex: the vertex in question
 *
 * Return: no return
 */
void enqueue(queue_t *q, vertex_t *vertex)
{
	if (q->front == 0 && q->rear == 0)
	{
		q->arr[q->front] = vertex;
		q->rear = 1;
		return;
	}
	q->arr[q->rear] = vertex;
	q->rear++;
}

/**
 * dequeue - removes a vertex from the queue (LIFO)
 * @q: the queue in queuestion
 *
 * Return: the vertex q->arr[q->front]
 */
vertex_t *dequeue(queue_t *q)
{
	vertex_t *vertex;

	vertex = q->arr[q->front];
	q->front++;
	if (q->front > q->rear)
	{
		memset(q->arr, 0, q->size);
		q->front = 0;
		q->rear = 0;
	}
	return (vertex);
}

/**
 * free_queue - frees a queue
 * @q: the q to free
 *
 * Return: no return
 */

void free_queue(queue_t *q)
{
	free(q->arr);
	free(q);
}
