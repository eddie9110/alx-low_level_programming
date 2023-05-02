#include <stddef.h>
#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - ftn that will inser a new node on linked list
 * @head: pointer to the first node
 * @idx: position to add new node
 * @n: new node data
 * Return: a pointer to new node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *nnode;
	listint_t *prtr = *head;
	unsigned int dx;


	nnode = malloc(sizeof(listint_t));

	if (!head || !nnode)
		return (NULL);


	nnode->n = n;
	nnode->next = NULL;

	if (idx == 0)
	{
		nnode->next = *head;
		*head = nnode;
		return (nnode);
	}


	for (dx = 0 ; prtr && dx < idx ; dx++)
	{
		if (dx == idx - 1)
		{
			nnode->next = prtr->next;
			prtr->next = nnode;
			
			return (nnode);
		} else
			prtr = prtr->next;
	}
	return (NULL);
}

