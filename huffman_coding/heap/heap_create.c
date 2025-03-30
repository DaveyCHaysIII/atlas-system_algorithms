#include "heap.h"

/**
 * heap_create - create and initialize a heap
 * @data_cmp: function pointer to add to member data_cmp
 *
 * Return: pointer to created heap
 */

heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new_heap;

	new_heap = malloc(sizeof(heap_t));
	if (!new_heap)
		return (EXIT_FAILURE);
	new_heap->size = 0;
	new_heap->data_cmp = data_cmp;
	new_heap->root = NULL;

	return (new_heap);
}
