#include "main.h"
#include <stdlib.h>

/**
 * _calloc - custom made calloc ftn
 * @nmemb: elements in array
 * @size: bytes to be allocated to array
 * Return: a pointer uy
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *uy;
	unsigned int ke;

	if (nmemb == 0 || size == 0)
		return (NULL);

	uy = malloc(nmemb * size);

	if (uy == NULL)
		return (NULL);
	for (ke = 0; ke < (nmemb * size); ke++)
		uy[ke] = 0;
	return (uy);
}
