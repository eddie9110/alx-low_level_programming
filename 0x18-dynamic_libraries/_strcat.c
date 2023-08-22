#include "main.h"

/**
 * _strcat - concatenates two strings
 *
 *@src: first string
 *@dest: second string
 *
 *Return: dest string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	dest[i] = ' ';
	for (j = 0; src[j] != '\0'; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
