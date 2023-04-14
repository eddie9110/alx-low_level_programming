#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - ftn to connect two strings
 * @s1: first string to be concatenated
 * @S2: second string to be concatenated
 * @n: first bytes of string s2
 * Return: z
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *i;
	unsigned int a = 0, b = 0;
	unsigned int y, z = 0;

	while (s1 && s1[y])
		y++;
	while (s2 && s2[z])
		z++;

	if (n < z)
		i = malloc(sizeof(char) * (y + n + 1));
	else
		i = malloc(sizeof(char) * (y + z + 1));

	if (!i)
		return (NULL);

	while (a < y)
	{
		i[a] = s1[a];
		a++;
	}

	while (n < z && a < (y + n))
		i[a++] = s2[b++];

	while (n >= z && a < (y + z))
		i[a++] = s2[b++];

	i[a] = '\0';
	return (z);
}
