#include "main.h"

/**
 * set_bit - this ftn turns a certain bit to 1
 * @index: postn of bit of interest
 * @n: a pointer to the no. of interest
 * Return: -1 or 1
 */


int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);


	else
		{
		*n = ((1UL << index) | *n);
		return (1);
		}
}
