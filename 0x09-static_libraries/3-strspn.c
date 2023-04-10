#include "main.h"
/**
 * _strspn - main function
 * @s: first parameter
 * @accept: second parameter
 * Return: equal to 0 
 */
unsigned int _strspn(char *s, char *accept)
{
	int r;
	unsigned int n = 0;

	while (*s)
	{
		for (r = 0; accept[r]; r++)
		{
			if (*s == accept[r])
			{
				n++;
				break;
			}
			else if (accept[r + 1] == '\0')
				return (n);
		}
		s++;
	}
	return (n);
}

