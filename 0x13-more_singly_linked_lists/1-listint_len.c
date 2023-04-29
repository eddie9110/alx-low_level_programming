#include <stddef.h>
#include "lists.h"

/**
 * listint_len - ftn to calculate the no. of elements in a linked list
 * @h: pointer to the head of the linked list
 * Return: the no. of elements in linked list
 *
 */

size_t listint_len(const listint_t *h)
{
	int otp = 0;
	/*otp contains the no. of elements in the linked list*/


	while (h)
	{
		h = h->next;
		otp++;
	}
	return (otp);
}
