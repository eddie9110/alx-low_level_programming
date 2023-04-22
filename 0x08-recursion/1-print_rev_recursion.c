#include "main.h"

/**
 *  _print_rev_recursion - name of fuctn to print string in reverse
 *  @s: parameter reps string passed to ftn
 *  return: equal to void
 */


void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);

	}
}
