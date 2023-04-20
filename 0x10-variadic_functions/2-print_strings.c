#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - ftn that outputs strings
 * @separator: reps the string to separate the output string
 * @n: reps n0. of strings passed to ftn
 * @...: reps varying arguments paased to ftn
 * Return: no return
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int kk;
	char *s;
	va_list str;

	va_start(str, n);

	for (kk = 0 ; kk < n ; kk++)
	{
		s = va_arg(str, char*);
		if (s == NULL)
			printf("(nil)");
		else
			printf("%s", s);

		if (kk != (n - 1) && separator != NULL)
			printf("%s", separator);
	} printf("\n");


	va_end(str);
}
