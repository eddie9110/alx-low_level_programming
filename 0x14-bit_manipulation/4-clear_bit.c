#include "main.h"

/**
 * clear_bit - a ftn that sets the value of a bit to 0 at a given index
 * @index: the position of the no. of interest
 * @n: the no. of interest
 * Return: 1 - success / -1 fail
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 64)
		return (-1); /*checks if index is greatr that or equal to 64 for error handling*/

	*n = (~(1 << index) & *n);

	return (1);
}
