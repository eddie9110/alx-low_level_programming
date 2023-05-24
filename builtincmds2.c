#include "shell.h"

/**
 * cst_histlst - ftn to display the history list, one command per line.
 * @info: Maintains constant function prototype.
 *  Return: 0.
 */

int cst_histlst(pssdinfo *info)
{
	cst_printlist(info->history);
	return (0);
}

/**
 * cst_unsetalias - ftn that unsets an alias to a string.
 * @info: a struct parameter.
 * @str: String alias.
 * Return: Always 0 for success, 1 for an error.
 */

int cst_unsetalias(pssdinfo *info, char *str)
{
	char *ya, rt;
	int rtrn;

	ya = cststr_char(str, '=');
	if (!ya)
		return (1);
	rt = *ya;
	*ya = 0;

	rtrn = cstdeletenodeatindx(&(info->alias),
		cst_getnodeindx(info->alias, cst_ndestartswith(info->alias, str, -1)));

	*ya = rt;
	return (rtrn);
}

/**
 * cst_setalias - ftn to set an alias to a string.
 * @info: Parameter structure.
 * @str: Alias for string.
 * Return: Always 0 for success, 1 for error.
 */

int cst_setalias(pssdinfo *info, char *str)
{
	char *sd;

	sd = cststr_char(str, '=');
	if (!sd)
		return (1);
	if (!*++sd)
		return (cst_unsetalias(info, str));

	cst_unsetalias(info, str);
	return (cstaddnodeatend(&(info->alias), str, 0) == NULL);
}

/**
 * cstprnt_alias - ftn that will output an alias string.
 * @node: Node of the alias.
 * Return: Always 0 if successful, 1 for failure.
 */

int cstprnt_alias(str_lst *node)
{
	char *xe = NULL, *by = NULL;

	if (node)
	{
		xe = cststr_char(node->str, '=');

		for (by = node->str; by <= xe; by++)
			myput_char(*by);

		myput_char('\'');
		cst_puts(xe + 1);
		cst_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * cst_alias - a ftn that is similar to alias in functionality
 * @info: Structure containing possible arguments.
 *  Return: 0.
 */

int cst_alias(pssdinfo *info)
{
	char *ev = NULL;
	int jx = 0;
	str_lst *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			cstprnt_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (jx = 1; info->argv[jx]; jx++)
	{
		ev = cststr_char(info->argv[jx], '=');
		if (ev)
			cst_setalias(info, info->argv[jx]);
		else
			cstprnt_alias(cst_ndestartswith(info->alias, info->argv[jx], '='));
	}

	return (0);
}
