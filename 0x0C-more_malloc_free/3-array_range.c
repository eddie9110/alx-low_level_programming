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
	int cap;
	int x;

	if (min > max)
		return (NULL);

	cap = max - min + 1;

	ke = malloc(sizeof(int) * cap);


	if (ke == NULL)
		return (NULL);

	for (x = 0; min <= max; x++)
		ke[x] = min++;

	return (ke);
}

