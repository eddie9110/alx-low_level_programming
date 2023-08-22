#include "main.h"

/**
 * _strlen - returns legth of s
 * @s: string
 *
 * Return: length
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
