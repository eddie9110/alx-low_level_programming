#include "shell.h"

/**
 * cstget_environ - ftn to get string array copy of usr's environment.
 * @info: Structure containing possible arguments.
 * Return: Always 0.
 */

char **cstget_environ(pssdinfo *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = cst_listtostrings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * cstunset_environ - ftn that unsets an environment variable.
 * @info: Structure containing possible arguments.
 * @var: Variable environment.
 *  Return: 1 on deletion, else - (0).
 */

int cstunset_environ(pssdinfo *info, char *var)
{
	str_lst *node = info->env;
	size_t ju = 0;
	char *ui;

	if (!node || !var)
		return (0);

	while (node)
	{
		ui = starts_with(node->str, var);
		if (ui && *ui == '=')
		{
			info->env_changed = cstdeletenodeatindx(&(info->env), ju);
			ju = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		ju++;
	}
	return (info->env_changed);
}

/**
 * cstset_environ - ftn initializes or modifies an environment variable.
 * @info: Structure containing possible arguments.
 * @var: String environment variable.
 * @value: String environment variable value.
 *  Return: 0 as usual.
 */

int cstset_environ(pssdinfo *info, char *var, char *value)
{
	char *buf = NULL;
	str_lst *node;
	char *ok;


	if (!var || !value)
		return (0);

	buf = malloc(cststr_len(var) + cststr_len(value) + 2);
	if (!buf)
		return (1);
	cststr_cpy(buf, var);
	cststr_cat(buf, "=");
	cststr_cat(buf, value);
	node = info->env;

	while (node)
	{
		ok = starts_with(node->str, var);
		if (ok && *ok == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}

	cstaddnodeatend(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
