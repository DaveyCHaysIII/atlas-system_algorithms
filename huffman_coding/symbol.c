#include "huffman.h"

/**
 * symbol_create - creates a symbol
 * @data: the character
 * @freq: the frequency of that character
 *
 * Return: newly created symbol
 */

symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new_symbol;

	if (!data || !freq)
		return (NULL);
	new_symbol = malloc(sizeof(symbol_t));
	if (!new_symbol)
		return (NULL);

	new_symbol->data = data;
	new_symbol->freq = freq;
	return (new_symbol);
}
