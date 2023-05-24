#include "shell.h"

/**
 **cststrn_cpy - a ftn that copies a string.
 *@dst: the destination string.
 *@srce: Source string.
 *@n: Amount of characters to be copied.
 *Return: Concatenated string.
 */

char *cststrn_cpy(char *dst, char *srce, int n)
{
	int ou, we;
	char *st = dst;

	ou = 0;
	while (srce[ou] != '\0' && ou < n - 1)
	{
		dst[ou] = srce[ou];
		ou++;
	}
	if (ou < n)
	{
		we = ou;
		while (we < n)
		{
			dst[we] = '\0';
			we++;
		}
	}
	return (st);
}

/**
 **cststrn_cat - ftn that concatenates 2 strings.
 *@dst: the first string.
 *@srce: the second string.
 *@n: the amount of bytes that will be used.
 *Return: (st)-concatenated string.
 */

char *cststrn_cat(char *dst, char *srce, int n)
{
	int xe, jg = 0;
	char *st = dst;

	while (dst[xe] != '\0')
		xe++;

	while (srce[jg] != '\0' && jg < n)
	{
		dst[xe] = srce[jg];
		xe++;
		jg++;
	}
	if (jg < n)
		dst[xe] = '\0';

	return (st);
}

/**
 **cststr_char - a ftn that looks for a character in a string.
 *@s: the tokenised string.
 *@c: the character of interest.
 *Return: a pointer to memory.(s)
 */

char *cststr_char(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
