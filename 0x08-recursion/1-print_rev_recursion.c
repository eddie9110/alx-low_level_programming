#include "main.h"

/**
 *  _print_rev_recursion - name of fuctn
 *  @char *s: parameter of ftcn above
 *  return: equal to void
 */

void _print_rev_recursion(char *s);
{
	if (*s)
	{
		_print_rev_recursion;
		_putchar(*s);
	}
}
