#include "main.h"

/**
 * get_bit - a ftn that a bit's value at a certain position
 * @n: the no. of interest
 * @index: pstn of the no. of interest
 * Return: the bit's value
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int valbt;


	valbt = (n >> index) & 1;

	return (valbt);

	if (index > 63)
		return (-1);
}
