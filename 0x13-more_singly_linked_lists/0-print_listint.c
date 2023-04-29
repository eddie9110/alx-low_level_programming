#include <stddef.h>
#include "lists.h"
#include <stdio.h>

/**
 * print_listint - ftn to count no. of elements in string
 * @h: pointer to the head of the list
 * Return: opt (no. of elements in linked list)
 *
 */

size_t print_listint(const listint_t *h)
{
	/*opt is a variable that contains the no. of elements in the linked list*/

	size_t opt = 0;

	while (h != NULL)
	{
		opt++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (opt);
}
