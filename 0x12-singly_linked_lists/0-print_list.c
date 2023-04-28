#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include<stdio.h>

/**
 * print_list - ftn that prints contents of a list
 * @h: a pointer to head of list
 * Return: op(no. of elements in list nodes)
 */

size_t print_list(const list_t *h)
{
	size_t op = 0;


	while (h)
	{
		if (!h->str)
		{
			printf("[0] (nil)\n");
		} else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		h = h->next;
		op++;
	}
	return (op);
}
