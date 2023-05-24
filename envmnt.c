#include "shell.h"

/**
 * cstprt_env - ftn that prints the current environment of user.
 * @info: Structure containing possible arguments.
 * Return: Always 0
 */

int cstprt_env(pssdinfo *info)
{
	cst_printliststr(info->env);
	return (0);
}

/**
 * cstget_env - ftn that fetches the value of an environment variable.
 * @info: Structure containing possible arguments.
 * @name: Name of environment variable
 * Return: value of variable.
 */

char *cstget_env(pssdinfo *info, const char *name)
{
	str_lst *node = info->env;
	char *ad;

	while (node)
	{
		ad = starts_with(node->str, name);
		if (ad && *ad)
			return (ad);
		node = node->next;
	}
	return (NULL);
}

/**
 * cstset_env - ftn that initialises or modifies an environment variable.
 * @info: Structure containing possible arguments.
 *  Return: 0 as usual.
 */

int cstset_env(pssdinfo *info)
{
	if (info->argc != 3)
	{
		cstaputs("Inaccurate no. of arguments\n");
		return (1);
	}
	if (cstsetenviron(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * cstunset_env - ftn that deletes an environment variable.
 * @info: Structure containing possible arguments.
 *  Return: 0 as usual.
 */

int cstunset_env(pssdinfo *info)
{
	int re;

	if (info->argc == 1)
	{
		cstaputs("Arguments are too few.\n");
		return (1);
	}
	for (re = 1; re <= info->argc; re++)
		cstunset_environ(info, info->argv[re]);

	return (0);
}

/**
 * cstgenenv_list - ftn that generates environment linked lists.
 * @info: Structure containing possible arguments.
 * Return: 0 as usual.
 */

int cstgenenv_list(pssdinfo *info)
{
	str_lst *node = NULL;
	size_t jc;

	for (jc = 0; environ[jc]; jc++)
		cstaddnodeatend(&node, environ[jc], 0);

	info->env = node;

	return (0);
}
