#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - ftn to add node at end of list
 * @head: pointer to list
 * @str: data for new node
 * Return: link of new node
 */

list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int len = 0;
	list_t *nnode;
	list_t *t = *head;


	while (str[len])
		len++;

	nnode = malloc(sizeof(list_t));
	if (!nnode)
                return (NULL);


	nnode->str = strdup(str);
	nnode->len = len;
	nnode->next = NULL;

	if (*head == NULL)
	{
		*head = nnode;
		return (nnode);
	}

	while (t->next)
		t = t->next;

	t->next = nnode;

	return (nnode);
}
