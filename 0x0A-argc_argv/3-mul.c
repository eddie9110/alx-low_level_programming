#include <stdio.h>
#include <stdlib.h>

/**
 * main - its the start and end of the prog
 * @argc: argument counter
 * @argv: argument displaying ftn
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int x, y, z;

	if (argc != 3)
	{
		printf("error\n");
		return (1);
	}
	else
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		z = y * x;
		printf("%d\n", z);
	}
	return (0);
}
