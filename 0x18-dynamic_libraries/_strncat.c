#include "main.h"

/**
 * _strncat - concatenates two strings
 *
 *@src: first string
 *@dest: second string
 *@n: number of bytes
 *
 *Return: dest string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	dest[i] = ' ';
	for (j = 0; src[j] != '\0' && j < n; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
