#include "main.h"
/**
 *factorial - this function provides the factorial of a no.
 *@n: parameter of interest
 *Return: the return as a datatype of int
 */

int factorial(int n)
{

	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
