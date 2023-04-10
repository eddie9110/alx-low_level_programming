#include "main.h"
/**
 * _memset - the main ftn
 * @s: this is the starting address of memory to be filled
 * @b: econd parameter equal to value of interest
 * @n: third parameter equal to bytes to be changed
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
