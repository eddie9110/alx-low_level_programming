#include "lists.h"

/**
 * add_dnodeint_end - aftn that adds a new
 * node at the end of a dlistint_t list.
 * @head: head node
 * @n: data
 * Return: address of new element or null
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *n_node, *t_ptr;

	n_node = malloc(sizeof(dlistint_t));

	if (!n_node)
		return (NULL);

	n_node->next = NULL;
	n_node->n = n;

	if (!(*head))
	{
		n_node->prev = NULL;
		*head = n_node;
	}
	else
	{
		for (t_ptr = *head; t_ptr->next; t_ptr = t_ptr->next)
			;
		n_node->prev = t_ptr;
		t_ptr->next = n_node;
	}

	return (n_node);
}
