#include "main.h"

/**
 * get_endianness - ftn to check whether byte order is big or small endian
 * Return: (1) - big endian / (0) little endian
 */

int get_endianness(void)
{
	int jx = 1,
	int yh = 1;
	int outp = 0;


	outp = (jx & yh);

	return (outp);
}
