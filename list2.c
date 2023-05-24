#include "shell.h"

/**
 * cst_listlen - ftn that returns the string length.
 * @h: Pointer to first node.
 * Return: list len.
 */

size_t cst_listlen(const str_lst *h)
{
	size_t yl = 0;

	while (h)
	{
		h = h->next;
		yl++;
	}
	return (yl);
}

/**
 * cst_listtostrings - ftn that returns an array of strings of the list ->str.
 * @head: Pointer to the first node.
 * Return: Array of strings.
 */


char **cst_listtostrings(str_lst *head)
{
	str_lst *node = head;
	char **strs;
	size_t qe = cst_listlen(head), rf;
	char *str;

	if (!head || !qe)
		return (NULL);

	strs = malloc(sizeof(char *) * (qe + 1));

	if (!strs)
		return (NULL);

	for (qe = 0; node; node = node->next, qe++)
	{
		str = malloc(cststr_len(node->str) + 1);

		if (!str)
		{
			for (rf = 0; rf < qe; rf++)
				free(strs[rf]);
			free(strs);
			return (NULL);
		}

		str = cststr_cpy(str, node->str);
		strs[qe] = str;
	}
	strs[qe] = NULL;
	return (strs);
}


/**
 * cst_printlist - ftn that prints all elements of a list_t list.
 * @h: Pointer to first node.
 * Return: List size.
 */

size_t cst_printlist(const str_lst *h)
{
	size_t oy = 0;

	while (h)
	{
		cst_puts(cstconvnumb(h->num, 10, 0));
		myput_char(':');
		myput_char(' ');
		cst_puts(h->str ? h->str : "(nil)");
		cst_puts("\n");
		h = h->next;
		oy++;
	}
	return (oy);
}

/**
 * cst_ndestartswith - ftn that returns node of a certain prefix.
 * @node: a pointer to first item in list.
 * @prefix: string to match.
 * @c: next character after prefix.
 * Return: node of desired prefix on success or NULL on failure.
 */


str_lst *cst_ndestartswith(str_lst *node, char *prefix, char c)
{
	char *yu = NULL;

	while (node)
	{
		yu = starts_with(node->str, prefix);
		if (yu && ((c == -1) || (*yu == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}


/**
 * cst_getnodeindex - a ftn that obtains index of a node.
 * @head: a pointer to first item in list.
 * @node: a pointer to the node.
 * Return: the index of node on success or -1 on failure.
 */

ssize_t cst_getnodeindex(str_lst *head, str_lst *node)
{
	size_t mc = 0;

	while (head)
	{
		if (head == node)
			return (mc);
		head = head->next;
		mc++;
	}
	return (-1);
}
