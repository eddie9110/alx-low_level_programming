#include "main.h"

/**
 * binary_to_uint - a ftn that will convert a bin no. to a dec int no.
 * @b: a pointer to the no. of interest
 * Return: an unsigned int which is the converted no.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int okl = 0;
	int na;


	for (na = 0 ; b[na] ; na++)
	{
		if (b[na] < '0' || b[na] > '1')
			return (0);
		okl = (b[na] - '0') + okl * 2;
	}

	return (okl);

	if (!b)
		return (okl);
}
