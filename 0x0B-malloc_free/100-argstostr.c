#include "main.h"
#include <stdlib.h>

/**
 * argstostr - ftn concatenates all the arguments of program
 * @ac: first parameter
 * @av: parameter is pointer to a char pointer
 * Return: a pointer ptr
 */

char *argstostr(int ac, char **av)
{
	int a, b, c, z  = 0;
	char *ptr;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b]; b++)
			z++;
	}
	z += ac;

	ptr = malloc(sizeof(char) * z + 1);
	if (ptr == NULL)
		return (NULL);
	for (a = 0; a < ac; a++)
	{
	for (b = 0; av[a][b]; b++)
	{
		ptr[c] = av[a][b];
		c++;
	}
	if (ptr[c] == '\0')
	{
		ptr[c++] = '\n';
	}
	}
	return (ptr);
}
