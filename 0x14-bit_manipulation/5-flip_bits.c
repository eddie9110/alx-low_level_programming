#include "main.h"

/**
 * flip_bits - aftn that outputs the no. of flips needed to move betwn no.s
 * @n: !st no.
 * @m: 2nd no.
 * Return: no. of flps needed
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int rsftone;
	int fcv = 0;
	unsigned long int rsftwo = n^m ;
	int cntt = 0;


	for (fcv = 63; fcv >= 0; fcv--)
	{
		rsftone = rsftwo >> fcv;

		if (rsftone & 1)
			cntt++;

	}

	return (cntt);

}
