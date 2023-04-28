#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 * add_node - ftn to add node at beginning of list
 * @head: pointer to list
 * @str: element to be added to node
 */

list_t *add_node(list_t **head, const char *str)
{
	unsigned int len = 0;
	list_t *prtr;


	while (str[len])
		len++;

	prtr = malloc(sizeof(list_t));
	prtr->str = strdup(str);
	prtr->len = len;
	prtr->next = (*head);
	(*head) = prtr;

	return (*head);

	if (!prtr)
	{
		return (NULL);
	}
}
