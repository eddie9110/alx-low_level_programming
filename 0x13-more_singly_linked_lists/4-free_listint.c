#include <stddef.h>
#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - ftn that frees memory allocated to new node
 * @head: pointer to head of linked list to be freed
 * Return: no return
 *
 */


void free_listint(listint_t *head)
{
	listint_t *prtr;

	while (head)
	{
		prtr = head->next;
		free(head);
		head = prtr;
	}
}
