#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - ftn returns a pointer to a 2d array of integers
 * @width: parameter one
 * @height: parameter two
 * Return: a
 */

int **alloc_grid(int width, int height)
{
	int **a;
	int j, k;

	if (width <= 0 || height <= 0)
		return (NULL);

	a = malloc(sizeof(int *) * height);

	if (a == NULL)
		return (NULL);

	for (j = 0; j < height; j++)
	{
		a[j] = malloc(sizeof(int) * width);

		if (a[j] == NULL)
		{
			for (; j >= 0; j--)
				free(a[j]);

			free(a);
			return (NULL);
		}
	}

	for (j = 0; j < height; j++)
	{
		for (k = 0; k < width; k++)
			a[j][k] = 0;
	}

	return (a);
}

