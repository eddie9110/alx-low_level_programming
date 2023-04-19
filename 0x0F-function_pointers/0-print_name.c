#include <stdio.h>
#include "function_pointers.h"


/**
 * print_name - ftn that will prnt name from a pointer name
 *@name: pointer parameter pointing to name to be printed
 * @f: the fctn pointer
 * Return: no return value (void)
 */


void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
