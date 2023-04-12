#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - ftn frees a 2D previously created
 * @grid: first parameter
 * @height: second parameter
 * Return: void
 */

void free_grid(int **grid, int height)
{
	int c;

	for (c = 0; c < height; c++)
	{
		free(grid[c]);
	}
	free(grid);
}
