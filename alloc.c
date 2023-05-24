#include "shell.h"

/**
 *cstsetmem - a ftn that fills a memory block with constant byte.
 *@s: a pointer to memory location.
 *@b: the byte to fill.
 *@n: Amount of bytes to be filled.
 *Return: Pointer to the memory location s.
 */

char *cstsetmem(char *s, char b, unsigned int n)
{
	unsigned int jh;

	for (jh = 0; jh < n; jh++)
		s[jh] = b;

	return (s);
}

/**
 * cstfree - a ftn that frees a string of strings.
 * @pp: The string of strings.
 */

void cstfree(char **pp)
{
	char **vt = pp;

	if (!pp)
		return;

	while (*pp)
		free(*pp++);

	free(vt);
}

/**
 * cstrealloc - a ftn similar to realloc that reallocates a block of memory.
 * @ptr: Pointer to previous malloc'ated block.
 * @old_size: Size of previous block.
 * @new_size: Size of new block.
 * Return: Pointer to
 */

void *cstrealloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *re;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
		return (free(ptr), NULL);

	if (new_size == old_size)
		return (ptr);
/* */
	re = malloc(new_size);

	if (!re)
		return (NULL);
/* */
	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		re[old_size] = ((char *)ptr)[old_size];

	free(ptr);
	return (re);
}
