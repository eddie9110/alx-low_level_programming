#include "lists.h"

/**
 * dlistint_len - aftn that returns the no of elements in a linked list
 * @h: head ptr
 * Return: no of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t xo;

	for (xo = 0; h; h = h->next, xo++)
		;
	return (xo);
}
