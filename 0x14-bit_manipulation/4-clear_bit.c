#include "main.h"

/**
 * clear_bit - ftn that converts bit to zero
 * @n: pointer to no. of interest
 * @index: no. of bit of interest.
 * Return: 1 or -1 if failed
 */


int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	else

		{
		*n = (~(1UL << index) & *n);
		return (1);
		}
}
