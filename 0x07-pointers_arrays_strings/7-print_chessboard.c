#include "main.h"
/**
 * print_chessboard - Main funtion which is the Entry point
 * @a: array parameter
 * Return: 0
 */
void print_chessboard(char (*a)[8])
{
	int j;
	int i;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			_putchar(a[i][j]);
		_putchar('\n');
	}
}
