#include "search_algos.h"

/**
 * binary_search_ftn - binary_search_ftn
 * @array: array
 * @min: min
 * @max: max
 * @value: value
 * Return: index / -1
 */

int binary_search(int *array, size_t size, int value)
{
	int max, mid, min;

	max = (int)size - 1;
	min = 0;

	if (!array)
		return (-1);

	while (min <= max)
	{
		print_ftn(array, min, max);
		mid = (min + max) / 2;
		if (array[mid] < value)
			min = mid + 1;
		else if (array[mid] > value)
			max = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

/**
 * print_ftn - ftn to print the array
 * @arr: ptr to first element
 * @start: first element
 * @end: last element
 */

void print_ftn(int *arr, int start, int end)
{
	printf("Searching in array: ");
	for (; start <= end; start++)
	{
		if (start == end)
			printf("%d\n", arr[start]);
		else
			printf("%d, ", arr[start]);
	}
}
