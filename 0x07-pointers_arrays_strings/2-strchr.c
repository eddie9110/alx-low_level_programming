#include "main.h"
/**
 * _strchr - s is the main ftn 
 * @c: input in the form of a character
 * @s: input which is a character
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
