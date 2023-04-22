#include "main.h"

/**
 * _pow_recursion - ftn that will return x raised to power y recursively
 * @x: parameter that will be the exponent
 * @y: parameter that will be the value of the raise
 * Return: x^y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}

	if (y == 0)
	{
		return (1);

	} return (x * _pow_recursion(x, y - 1));

}
