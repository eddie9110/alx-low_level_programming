#include "main.h"

/**
 * _realloc - custom realloc ftn
 * @ptr: parameter
 * @old_size: second parameter
 * @new_size: third parameter
 * Return: pointer st
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int k;
	char *st, *uv;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (!ptr)
		return (malloc(new_size));

	st = malloc(new_size);

	if (!st)
		return (NULL);

	uv = ptr;

	if (new_size < old_size)
	{
		for (k = 0; k < new_size; k++)
			st[k] = uv[k];
	}

	if (new_size > old_size)
	{
		for (k = 0; k < old_size; k++)
			st[k] = uv[k];
	}

	free(st);

	return (st);
}
