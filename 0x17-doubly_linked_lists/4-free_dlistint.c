#include "lists.h"

/**
 * free_dlistint - a ftn thatfrees a dlistint_t list.
 * @head: head node
 * Return: no return
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *t_ptr;

	while (head)
	{
		t_ptr = head->next;
		free(head);
		head = t_ptr;
	}
}
