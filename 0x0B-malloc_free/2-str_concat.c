#include "main.h"
#include <stdlib.h>

/**
 * str_concat - ftn that gets ends of input and adds them
 * @s1: first concat input
 * @s2: second concat input
 * Return: az if successful
 */
char *str_concat(char *s1, char *s2)
{
	char *az;
	int a, b;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	a = 0;
	b = 0;
	while (s1[a] != '\0')
		a++;
	while (s2[b] != '\0')
		b++;
	az = malloc(sizeof(char) * (a + b + 1));

	if (az == NULL)
		return (NULL);
	a = b = 0;
	while (s1[a] != '\0')
	{
		az[a] = s1[a];
		a++;
	}

	while (s2[b] != '\0')
	{
		az[a] = s2[b];
		a++, b++;
	}
	az[a] = '\0';
	return (az);
}

