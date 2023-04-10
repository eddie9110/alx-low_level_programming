#include "main.h"

/**
 * _isalpha -ftn that checks for alphabetic character
 * @c: parameter of interest
 * Return: 1 if successful 0 failed
 */

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
