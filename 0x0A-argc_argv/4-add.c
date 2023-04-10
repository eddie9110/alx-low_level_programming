#include <stdio.h>
#include <stdlib.h>

/**
 * main - main ftn
 *@argc: para counter
 *@argv: parameter displayer
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int x, y;

	if (argc == 1)
	{
                printf("0\n");
	}
        else
	{
		for (x = 1 ; x < argc ; x++)
		{
			if (!atoi(argv[x]))
			{
				printf("Error\n");
				return (1);
			}
			else
				y = y + atoi(argv[x]);
		}
                printf("%d\n", y);
	}
	return (0);
}
