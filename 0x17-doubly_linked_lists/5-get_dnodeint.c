#include "lists.h"

/**
 * get_dnodeint_at_index - a ftn that returns the
 * nth node of a dlistint_t linked list.
 * @head: head node
 * @index: the index of the node, starting from 0
 * Return: the nth node of a dlistint_t linked list or null
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int xo;

	if (!head)
		return (NULL);

	for (xo = 0; head->next && xo < index; xo++, head = head->next)
		;
	if (xo == index)
		return (head);

	return (NULL);
}
