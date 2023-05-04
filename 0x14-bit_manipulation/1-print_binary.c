#include "main.h"

/**
 * print_binary - ftn to convert binary no. to decimal.
 * @n: no. to be converted
 * Return: no return
 */

void print_binary(unsigned long int n)
{
	int ek = 0;
	unsigned long int current;
	int cnt = 0;


	if (!cnt)
		_putchar('0');



	for (ek = 63; ek >= 0; ek--)
	{
		current = n >> ek;

		if (current & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}

}
