#include <stdlib.h>
#include "main.h"

/**
 * array_range - ftn that will create an int array
 * @min: parameter one
 * @max: parameter two
 * Return: pointer ke
 */

int *array_range(int min, int max)
{
	int *ke;
	int size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	ke = malloc(sizeof(int) * size);


	if (ke == NULL)
		return (NULL);

	for (int x = 0; min <= max; x++)
		ke[x] = min++;

	return (ke);
}

