#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - ftn to add new node at the beginning of linked list
 * @head: pointer to a pointer that points to first node on list
 * @n: data input to new node
 * Return: nnode if successful, NULL if ftn fails
 */


listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nnode;
	/* nnode is the new node to be added to beginning of linked list*/

	nnode = malloc(sizeof(listint_t));

	if (!nnode)
		return (NULL);

	nnode->n = n;
	nnode->next = *head;
	*head = nnode;

	return (nnode);
}
