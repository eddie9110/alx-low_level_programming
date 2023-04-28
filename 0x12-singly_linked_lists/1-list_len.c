#include "lists.h"
#include <stdio.h>

/**
 * list_len - ftn that counts no. of elements in all nodes
 * @h: pointer to head
 * Return: numer of elements in nodes
 */

size_t list_len(const list_t *h)
{
	size_t op = 0;

	if (h)
	{
		while (h != NULL)
		{
			h = h->next;
			op++;
		}
	}
	return (op);
}
