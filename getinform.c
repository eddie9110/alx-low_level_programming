#include "shell.h"

/**
 * clear_info - ftn that initialises pssdinfo structure.
 * @info: Structure address.
 */

void clear_info(pssdinfo *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - ftn that initialises pssdinfo structure.
 * @info: Structuure address.
 * @av: Argument vector.
 */

void set_info(pssdinfo *info, char **av)
{
	int kh = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = cststrtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = cststr_dup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (kh = 0; info->argv && info->argv[kh]; kh++)
			;
		info->argc = kh;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - ftn that frees pssdinfo structure.
 * @info: Structure address.
 * @all: True for all fields.
 */

void free_info(pssdinfo *info, int all)
{
	cstfree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			cstfreelst(&(info->env));
		if (info->history)
			cstfreelst(&(info->history));
		if (info->alias)
			cstfreelst(&(info->alias));
		cstfree(info->environ);
			info->environ = NULL;
		bfreeptr((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		myput_char(BUF_FLUSH);
	}
}
