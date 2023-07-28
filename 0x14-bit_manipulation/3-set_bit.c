#include "main.h"

/**
 * set_bit - a function that sets the value of a bit to 1 at a given index
 * @n - number of interest
 * @index - the position of the number of interest
 * Return: 1 - success / -1 for failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 64)
		return (-1); /*checks if no. position to return -1 = fail)*/


	*n = ((1 << index) | *n);

	return (1);
}
