#include <stddef.h>
#include "lists.h"

/**
 * sum_listint - ftn that sums up data of linked list
 * @head: pointer to the first node
 * Return: sum of all data
 */


int sum_listint(listint_t *head)
{
	listint_t *prtr = head;
	int sum = 0;

	while (prtr)
	{
		sum = sum + prtr->n;
		prtr = prtr->next;
	}
	return (sum);
}
