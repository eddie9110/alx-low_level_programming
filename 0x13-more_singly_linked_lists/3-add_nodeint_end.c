#include <stddef.h>
#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint_end - ftn to add node to the end of linked list
 * @head: double pointer to the head of linked list
 * @n: reps the data to be stored in the new node
 * Return: address of new node element
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nnode;
	listint_t *prtr = *head;


	nnode = malloc(sizeof(listint_t));

	nnode->n = n;
	nnode->next = NULL;


	if (*head == NULL)
	{
		*head = nnode;
		return (nnode);
	}
	while (prtr->next)
		prtr = prtr->next;

	prtr->next = nnode;

	return (nnode);


	if (!nnode)
		return (NULL);

}
