#include "main.h"

/**
 * _abs - prints absolue value
 * @a: parameter
 * Return: always a
 */

int _abs(int a)
{
	if (a < 0)
		a = (-a);
	else if (a >= 0)
		a = a;
	return (a);
}
