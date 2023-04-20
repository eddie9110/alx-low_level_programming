#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - ftn produces the addition of its parameters
 * @n: reps the amount of parameters passed to ftn
 * @...: indicated the remaining parameters to ftn
 * Return: 0 or added parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int kd = 0;
	unsigned int plusr = 0;
	
	va_list arg;

	if (n == 0)
		return (0);

	va_start(arg, n);

	for (kd = 0 ; kd < n ; kd++)
		plusr = plusr + va_arg(arg, int);

	va_end(arg);

	return (plusr);

}
