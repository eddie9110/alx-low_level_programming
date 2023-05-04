#include "main.h"

/**
 * get_bit - ftn to convert a binary in dec no.
 * @n: no. of interest
 * @index: postn of no.
 * Return: bit brny
 */


int get_bit(unsigned long int n, unsigned int index)
{
	int brny;


	if (index > 63)
		return (-1);

	brny = (n >> index) & 1;


	return (brny);
}
