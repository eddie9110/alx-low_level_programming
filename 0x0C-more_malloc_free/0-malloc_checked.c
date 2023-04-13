#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - custom malloc ftn
 * @b: the amount of bytes assigned
 * Return: a void pointer == str
 */

void *malloc_checked(unsigned int b)
{
	void *str;

	str = malloc(b);

	if (str == NULL)
	{
		exit(98);
	}
	return (str);
}
