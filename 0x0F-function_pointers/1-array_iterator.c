#include "function_pointers.h"

/**
 * array_iterator - fctn to output all elements in array
 * @array: pointer parameter to array of interest
 * @size: size of number of elements of interest
 * @action: ftn pointer to ftn of interest
 * Return: no return = void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int ko;

	if (action == NULL || array == NULL)
		return;

	for (ko = 0; ko < size; ko++)
	{
		action(array[ko]);
	}
}
