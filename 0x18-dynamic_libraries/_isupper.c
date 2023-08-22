#include "main.h"

/**
 * _isupper - checks for uppercase character.
 *@c: character to be checked
 *
 * Return: 1 if uppercase and 0 if lowercase.
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
