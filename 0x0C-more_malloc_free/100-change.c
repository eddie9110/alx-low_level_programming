#include "main.h"

/**
 * main - main ftn prints min. no. of coins to give change
 * @argc: total argument counter on terminal
 * @argv: argument displayer
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int count;
	int total;
	int coins[] = {25, 10, 5, 2, 1};
	int ze;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	count = atoi(argv[1]);
	total = 0;

	if (count < 0)
	{
		printf("0\n");
		return (0);
	}

	for (ze = 0; ze < 5 && count >= 0; ze++)
	{
		while (count >= coins[ze])
		{
			total++;
			count -= coins[ze];
		}
	}

	printf("%d\n", total);

	return (0);
}
