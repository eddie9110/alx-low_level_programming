#include "shell.h"

/**
 * cstaddnode - ftn that adds a node to the beginning of a list.
 * @head: Pointer's address.
 * @str: Field of node.
 * @num: Node index used by history.
 * Return: List size.
 */

str_lst *cstaddnode(str_lst **head, const char *str, int num)
{
	str_lst *new_head;

	if (!head)
		return (NULL);

	new_head = malloc(sizeof(str_lst));

	if (!new_head)
		return (NULL);

	cstsetmem((void *)new_head, 0, sizeof(str_lst));

	new_head->num = num;

	if (str)
	{
		new_head->str = cststr_dup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * cstaddnodeatend - ftn that adds a node to the end of a list.
 * @head: Address of pointer to node's head.
 * @str: String field of node.
 * @num: Node index used by history.
 * Return: size of list
 */

str_lst *cstaddnodeatend(str_lst **head, const char *str, int num)
{
	str_lst *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(str_lst));

	if (!new_node)
		return (NULL);
	cstsetmem((void *)new_node, 0, sizeof(str_lst));
	new_node->num = num;
	if (str)
	{
		new_node->str = cststr_dup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
/**
 * cst_printliststr - ftn that prints the str element of a str_lst linked list only.
 * @h: Pointer to first node.
 * Return: List size.
 */
size_t cst_printliststr(const str_lst *h)
{
	size_t jh = 0;

	while (h)
	{
		cst_puts(h->str ? h->str : "(nil)");
		cst_puts("\n");
		h = h->next;
		jh++;
	}
	return (jh);
}

/**
 * cstdeletenodeatindx - ftn that deletes a node at a specified index.
 * @head: Pointer's address to first node.
 * @index: Index of node to delete.
 * Return: 1 on success, 0 on failure.
 */

int cstdeletenodeatindx(str_lst **head, unsigned int index)
{
	str_lst *node, *prev_node;
	unsigned int kg = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (kg == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		kg++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * cstfreelst - a ftn that frees all the nodes in a list.
 * @head_ptr: a pointer's address to the head node.
 * Return: Void.
 */

void cstfreelst(str_lst **head_ptr)
{
	str_lst *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;

	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
