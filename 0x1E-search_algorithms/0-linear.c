#include "search_algos.h"

/**
 * linear_search - Linear search algorithm function
 * @array: array
 * @size: size
 * @value: value
 * Return: index / -1
 */

int linear_search(int *array, size_t size, int value)
{
	int ol;

	if (!array)
		return (-1);
	for (ol = 0; ol < (int)size; ol++)
	{
		printf("Value checked array[%d] = [%d]\n", ol, array[ol]);
		if (array[ol] == value)
			return (ol);
	}
	return (-1);
}
