#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * _strdup - _strdup ftn duplicates to new memory space location
 * @str: parameter in the form of char
 * Return: z
 */

char *_strdup(char *str)
{
	char *z;
	int a, b = 0;

	if (str == NULL)
		return (NULL);
	a = 0;
	while (str[a] != '\0')
		a++;

	z = malloc(sizeof(char) * (a + 1));

	if (z == NULL)
		return (NULL);

	for (b = 0; str[b]; b++)
		z[b] = str[b];

	return (z);
}
