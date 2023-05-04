#include "main.h"
/**
 * flip_bits - ftn that flips bits
 * @n: number to flip
 * @m: no. to flip
 * Return: no. of bits that have been flipped
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int cxe = n ^ m;
	int ui = 0;
	unsigned long int crnt;
	int ct = 0;


	for (ui = 63; ui >= 0; ui--)
	{
		if (crnt & 1)
			ct++;

		crnt = cxe >> ui;

	}


	return (ct);
}

