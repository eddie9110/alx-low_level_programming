#include "lists.h"

/**
 * add_dnodeint - a ftn to add a
 * new node at the beginning of a dlistint_t list.
 * @head: head node
 * @n: data
 * Return: address of new element
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *n_node;

	n_node = malloc(sizeof(dlistint_t));

	if (!n_node)
		return (NULL);

	n_node->prev = NULL;
	n_node->n = n;

	if (!(*head))
		n_node->next = NULL;
	else
	{
		n_node->next = *head;
		(*head)->prev = n_node;
	}

	*head = n_node;

	return (n_node);
}
