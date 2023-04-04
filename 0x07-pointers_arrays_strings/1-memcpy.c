#include "main.h"
/**
 *_memcpy - this function copies n bytes from memory area src to memory area dest
 *@src: memory where is copied
 *@n: number of bytes
 *@dest: memory where is stored
 *Return: copied memory with n bytes changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = n;
	int r = 0;

	for (; r < i; ++r)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
