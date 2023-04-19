#include "function_pointers.h"

/**
 * int_index - if array is null, -ve 1 is returned
 * @array: pointer parameter to array
 * @size: the size of the elemnts in the array of interest
 * @cmp: a pointer to a ftn
 * Return: negative one
 */


int int_index(int *array, int size, int (*cmp)(int))
{
	int zk;


	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (zk = 0; zk < size; zk++)
	{
		if (cmp(array[zk]))
			return (zk);
	}

	return (-1);

}
