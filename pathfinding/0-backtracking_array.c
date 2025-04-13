#include "pathfinding.h"

int bt_recurse(queue_t *q,
	       int **visited,
	       char **map,
	       int rows,
	       int cols,
	       int x,
	       int y,
	       point_t const *target);
/**
 * backtracking_array - backtracking algo through an array
 * @map: 2d char array of "0" and "1"
 * @rows: number of rows
 * @cols: number of columns
 * @start: the starting position of the search
 * @target: the position we're trying to reach
 *
 * Return: queue of final path
 */

queue_t *backtracking_array(char **map,
			    int rows,
			    int cols,
			    point_t const *start,
			    point_t const *target)
{
	if (!map || !rows || !cols || !start || !target)
		return (NULL);

	int i;
	int **visited = malloc(rows * sizeof(int *));

	if (!visited)
		return (NULL);
	for (int i = 0; i < rows; i++)
	{
		visited[i] = calloc(cols, sizeof(int));
	}

	queue_t *new_queue = queue_create();

	if (!bt_recurse(new_queue,
		   visited,
		   map,
		   rows,
		   cols,
		   start->x,
		   start->y,
		   target))
	{
		for (i = 0; i < rows; i++)
		{
			free(visited[i]);
		}
		free(visited);
		free(new_queue);
		return (NULL);
	}
	for (i = 0; i < rows; i++)
	{
		free(visited[i]);
	}
	free(visited);
	return (new_queue);
}

/**
 * bt_recurse - recurses through the char **map
 * @q: the queue
 * @visited: the int **array (mapped to "map")
 * @map: the char **array we're traversing
 * @rows: the number of rows in map
 * @cols: the number of cols in map
 * @x: the current x location
 * @y: the current y location
 * @target: the point_t holding the target x and y
 *
 * Return: 0 or 1
 */

int bt_recurse(queue_t *q,
	       int **visited,
	       char **map,
	       int rows,
	       int cols,
	       int x,
	       int y,
	       point_t const *target)
{
	if (x < 0 || x >= cols ||
	    y < 0 || y >= rows ||
	    map[y][x] == '1' || visited[y][x])
		return (0);

	visited[y][x] = 1;
	printf("Checking coordinates [%d, %d]\n", x, y);
	if ((x == target->x && y == target->y) ||
	     bt_recurse(q, visited, map, rows, cols, x + 1, y, target) ||
	     bt_recurse(q, visited, map, rows, cols, x, y + 1, target) ||
	     bt_recurse(q, visited, map, rows, cols, x - 1, y, target) ||
	     bt_recurse(q, visited, map, rows, cols, x, y - 1, target))
	{
		point_t *current = malloc(sizeof(point_t));

		current->x = x;
		current->y = y;
		queue_push_front(q, (void *)current);
		return (1);
	}
	else
		return (0);
}
