#include "main.h"

/**
 * _strncpy - concatenates two strings
 *
 *@src: first string
 *@dest: second string
 *@n: number of bytes
 *
 *Return: dest string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
