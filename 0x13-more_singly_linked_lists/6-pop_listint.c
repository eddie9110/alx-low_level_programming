#include <stddef.h>
#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - ftn that will remove the head node of list
 * @head: a pointer to the first nodeof list
 * Return: 0 or xe
 */


int pop_listint(listint_t **head)
{
	int xe;
	listint_t *nnode;

	nnode = (*head)->next;
	xe = (*head)->n;
	free(*head);
	*head = nnode;

	return (xe);

	if (!*head || !head)
		return (0);
}
