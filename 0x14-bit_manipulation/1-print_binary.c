#include "main.h"

/**
 * print_binary - a ftn that outputs a bin of a de no.
 * @n: no. to convert to binary format
 * Return: void
 */

void print_binary(unsigned long int n)
{
	int ujc = 0;
	unsigned long int bnry;
	int cnt = 0;


	for (ujc = 63 ; ujc >= 0 ; ujc--)
	{
		bnry = n >> ujc;


		if (bnry & 1)
		{
			_putchar('1');
			cnt++;
		}

		else if (cnt)
			_putchar('0');
	}

	if (!cnt)
		_putchar('0');

}
