#include "main.h"
/**
 * _strstr - Entry point
 * @haystack: first parameter of interest
 * @needle: secparameter of interest
 * Return: Always 0 
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *p = needle;
		char *l = haystack;

		while (*l == *p && *p != '\0')
		{
			l++;
			p++;
		}

		if (*p == '\0')
			return (haystack);
	}

	return (0);
}
