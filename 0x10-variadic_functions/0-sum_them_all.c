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
	unsigned int kd, sum = 0;
	va_list argu;

	va_start(argu, n);

	if (n == 0)
		return (0);


	for (kd = 0 ; kd < n ; kd++)
	{
		sum += va_arg(argu, int);
	}

	va_end(argu);

	return (sum);
}
