#include "main.h"

/**
 * _puts_recursion - this function outputs a string
 * @s: this is the parameter of interest in the ftn mentioned above
 * return: no return because of void data type
 */

void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	} else
		_putchar('\n');
}
