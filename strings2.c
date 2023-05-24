#include "shell.h"

/**
 * cststr_cpy - ftn that copies a string.
 * @dst: the destination string.
 * @srce: the source string.
 * Return: a pointer to the location of the destination.
 */

char *cststr_cpy(char *dst, char *srce)
{
	int oi = 0;

	if (dst == srce || srce == 0)
		return (dst);

	while (srce[oi])
	{
		dst[oi] = srce[oi];
		oi++;
	}
	/* */
	dst[oi] = 0;
	return (dst);
}

/**
 * cststr_dup - ftn that duplicates a string.
 * @str: the string to be duplicated.
 * Return: a pointer to the duplicated string.
 */

char *cststr_dup(const char *str)
{
	int lgth = 0;
	char *retn;


	if (str == NULL)
		return (NULL);

	while (*str++)
		lgth++;

	retn = malloc(sizeof(char) * (lgth + 1));

	if (!retn)
		return (NULL);

	for (lgth++; lgth--;)
		retn[lgth] = *--str;

	return (retn);
}

/**
 *cst_puts - ftn that prints an input string.
 *@str: String to print.
 * Return: Blank.
 */

void cst_puts(char *str)
{
	int tx = 0;

	if (!str)
		return;

	while (str[tx] != '\0')
	{
		myput_char(str[tx]);
		tx++;
	}
}

/**
 * myput_char - ftn that prints the character c to stdout.
 * @ab: Character to print.
 * Return: 1 on success, else -1.
 */

int myput_char(char ab)
{
	static int re;
	static char buf[WRITE_BUF_SIZE];

	if (ab == BUF_FLUSH || re >= WRITE_BUF_SIZE)
	{
		write(1, buf, re);
		re = 0;
	}
	if (ab != BUF_FLUSH)
		buf[re++] = ab;
	return (1);
}
