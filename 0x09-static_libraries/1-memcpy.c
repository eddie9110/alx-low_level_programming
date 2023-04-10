#include "main.h"
/**
 *_memcpy - ftn that copies n bytes
 *@src: first parameter 
 *@n: second parameter
 *@dest: third parameter
 *Return: dest
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
