#include "shell.h"

/**
 * is_chain - ftn to test for chain delimeter.
 * @info: Parameter structure.
 * @buf: Character buffer.
 * @p: Current address position in buffer.
 * Return: 1 for chain delimeter, 0 otherwise.
 */

int is_chain(pssdinfo *info, char *buf, size_t *p)
{
	size_t rw = *p;

	if (buf[rw] == '|' && buf[rw + 1] == '|')
	{
		buf[rw] = 0;
		rw++;
		info->cmd_buf_type = CMD_OR;
	}

	else if (buf[rw] == '&' && buf[rw + 1] == '&')
	{
		buf[rw] = 0;
		rw++;
		info->cmd_buf_type = CMD_AND;
	}

	else if (buf[rw] == ';')
	{
		buf[rw] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}

	else
		return (0);
	*p = rw;
	return (1);
}

/**
 * check_chain - ftn that does checks
 * @info: Parameter structure.
 * @buf: Char buffer.
 * @p: Current address position in buffer.
 * @i: Starting position in buffer.
 * @len: Length of buffer.
 * Return: no return.
 */

void check_chain(pssdinfo *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t pl = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			pl = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			pl = len;
		}
	}

	*p = pl;
}

/**
 * replace_alias - ftn that replaces aliases in tokenized string.
 * @info: Parameter structure.
 * Return: 1 if replaced, 0 if otherwise.
 */

int replace_alias(pssdinfo *info)
{
	str_lst *node;
	int zx;
	char *ke;

	for (zx = 0; zx < 10; zx++)
	{
		node = cst_ndestartswith(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ke = cststr_char(node->str, '=');
		if (!ke)
			return (0);
		ke = cststr_dup(ke + 1);
		if (!ke)
			return (0);
		info->argv[0] = ke;
	}

	return (1);
}

/**
 * replace_vars - ftn that replaces vars in parsed string.
 * @info: Parameter structure.
 * Return: 1 if replaced, 0 otherwise.
 */

int replace_vars(pssdinfo *info)
{
	str_lst *node;
	int ty = 0;


	for (ty = 0; info->argv[ty]; ty++)
	{
		if (info->argv[ty][0] != '$' || !info->argv[ty][1])
			continue;

		if (!cststr_cmp(info->argv[ty], "$?"))
		{
			replace_string(&(info->argv[ty]),
				cststr_dup(cstconvnumb(info->status, 10, 0)));
			continue;
		}

		if (!cststr_cmp(info->argv[ty], "$$"))
		{
			replace_string(&(info->argv[ty]),
				cststr_dup(cstconvnumb(getpid(), 10, 0)));
			continue;
		}

		node = cst_ndestartswith(info->env, &info->argv[ty][1], '=');
		if (node)
		{
			replace_string(&(info->argv[ty]),
				cststr_dup(cststr_char(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[ty], cststr_dup(""));

	}
	return (0);
}

/**
 * replace_string - ftn that replaces a string.
 * @old: Address of old string.
 * @new: The new string.
 * Return: 1 if replaced, else 0.
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
