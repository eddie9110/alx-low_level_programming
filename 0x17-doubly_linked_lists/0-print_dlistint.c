#include "lists.h"

/**
 * print_dlistint -  prints all the elements of a dlistint_t list.
 * @h: head pointer
 * Return: no of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t ko;

	for (ko = 0; h; h = h->next, ko++)
		printf("%d\n", h->n);

	return (ko);
}
