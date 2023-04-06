#include "main.h"

/**
 *  _print_rev_recursion - name of fuctn
 *  @s: parameter of ftcn above
 *  return: equal to void
 */

void _print_rev_recursion(char *s){
        if (*s)
        {
                _print_rev_recursion(s + 1);
                _putchar(*s);
        } else
	       _putchar('\n');	
}
