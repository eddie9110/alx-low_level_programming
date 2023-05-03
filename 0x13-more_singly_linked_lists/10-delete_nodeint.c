#include <stddef.h>
#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - ftn that will delete node in linked list
 * @head: pointer to first node in linked list
 * @index: no of node to deleted in linked list
 * Return: prtr
 */


int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int dx = 0;
	listint_t *nnode = *head;
	listint_t *prtr = NULL;


	if (*head == NULL)
		return (-1);


	if (index == 0)
	{
		*head = (*head)->next;
		free(nnode);
		return (1);
	}


	while (dx < index - 1)
	{
		if (!nnode || !(nnode->next))
			return (-1);

		nnode = nnode->next;
		dx++;
	}


	prtr = nnode->next;
	nnode->next = prtr->next;

	free(prtr);
	return (1);
}
