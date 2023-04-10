#include "main.h"
/**
 * _strchr - the main ftn 
 * @c: parameter c is an input in the form of a character
 * @s: second parameter 
 * Return: 0 
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
