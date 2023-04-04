#include "main.h"
/**
 * _memset - this function will fill a block of memory with a certain value
 * @s: this is the starting address of memory to be filled
 * @b: the desired value
 * @n: represents the no. of bytes to that will be changed
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
