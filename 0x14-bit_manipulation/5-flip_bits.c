#include "main.h"

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

