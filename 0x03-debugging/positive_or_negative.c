#include "main.h"

/**
 * positive_or_negative - checks if a number is positive or negative
 *@i: parameter of interest
 */

void positive_or_negative(int i)
{
	if (i < 0)
		printf("%d is negative\n", i);
	else
		printf("%d is positive\n", i);
}
