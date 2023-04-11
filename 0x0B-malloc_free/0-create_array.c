#include "main.h"
#include <stdlib.h>

/**
 *create_array – ftn will create an array of size and assign char c
 *@size: parameter size will assign size
 *@c: parameter char to assign a character
 *Return: str  if successful and null if ftn fails
 */

char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int a;

	ptr = malloc(sizeof(char) * size);
	if (size == 0 || ptr == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
		ptr[a] = c;
	return (ptr);
}
