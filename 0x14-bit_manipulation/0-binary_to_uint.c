#include "main.h"

/**
 * binary_to_uint - ftn that will conver a binary no. to unsigned int
 * @b: pointer to string that has binary no.
 * Return: 0 for fail otherwise dcx
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int dcx = 0;
	int ui;


	for (ui = 0; b[ui]; ui++)
	{
		if (b[ui] < '0' || b[ui] > '1')
			return (0);
		dcx = 2 * dcx + (b[ui] - '0');
	}

	return (dcx);


	if (!b)
		return (0);
}
