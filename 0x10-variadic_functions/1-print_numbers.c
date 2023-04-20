#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_numbers - outputs no.s
 * @separator: reps string to print
 * @n: no.arguments passed to ftn
 * @...: reps additional arguments to be passed
 * Return: no return value
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int je = 0;
	va_list no;

	va_start(no, n);

	while (je < n)
	{
		printf("%d", va_arg(no, int));
		je++;
	}

	if (je != (n - 1) && separator != NULL)
			printf("%s", separator);

	printf("\n");

	va_end(no);
}
