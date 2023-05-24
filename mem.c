#include "shell.h"

/**
 * bfreeptr - ftn that frees a pointer then sets the address to NULL.
 * @ptr: the address of the ptr.
 * Return: 1 if memory is successfully freed, otherwise 0.
 */

int bfreeptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
