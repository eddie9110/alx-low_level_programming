#include <stddef.h>
#include "lists.h"
#include <stdlib.h>


/**
 * free_listint2 - ftn that will free a linked list
 * @head: pointer that points to list to be freed
 * Return: no return value
 */

void free_listint2(listint_t **head)
{
	listint_t *nnode;

	while (*head)
	{
		nnode =(*head)->next;
		free(*head);
		*head = nnode;
	}
	*head = NULL;
}
