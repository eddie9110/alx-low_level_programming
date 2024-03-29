#include "lists.h"

/**
 * sum_dlistint - ftn that returns the sum of all the
 * data of a dlistint_t linked list.
 * @head: head
 * Return: sum or 0
 */

int sum_dlistint(dlistint_t *head)
{
	int sum;

	for (sum = 0; head; head = head->next)
		sum += head->n;
	return (sum);
}
