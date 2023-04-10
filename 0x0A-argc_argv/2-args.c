#include <stdio.h>

/**
 * main - main ftn
 * @argc: counts parameters passed
 * @argv: displays all arguments passed
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int e;

	for (e = 0; e < argc ; e++)
		printf("%s\n", argv[e]);
	return (0);
}
