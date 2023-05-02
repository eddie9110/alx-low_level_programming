#include <stddef.h>
#include "lists.h"

/**
 * get_nodeint_at_index - ftn to retrieve a certain node
 * @head: pointer to first node in linked list
 * @index: no. of node to be retrieved
 * Return: a pointer to node of interest
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *prtr = head;
	unsigned int kd = 0;


	while (prtr && kd < index)
	{
		prtr = prtr->next;
		kd++;
	}
	return (prtr);
}
