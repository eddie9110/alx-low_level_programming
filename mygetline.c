#include "shell.h"

/**
 * input_buf - a ftn that combines commands in buffers.
 * @info: a struct parameter.
 * @bfr: the address of the buffer.
 * @len: Len variable address.
 * Return: (ag) - read bytes.
 */

ssize_t input_buf(pssdinfo *info, char **bfr, size_t *len)
{
	ssize_t ag = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*bfr);
		*bfr = NULL;
		signal(SIGINT, sigintHandler);

#if USE_GETLINE
		ag = getline(buf, &len_p, stdin);
#else
		ag = cstget_line(info, bfr, &len_p);
#endif

		if (ag > 0)
		{
			if ((*bfr)[ag - 1] == '\n')
			{
				(*bfr)[ag - 1] = '\0';
				ag--;
			}
			info->linecount_flag = 1;

			cstrmvcomments(*bfr);
			cst_buildhistlist(info, *bfr, info->histcount++);
			{
				*len = ag;
				info->cmd_buf = bfr;
			}
		}
	}
	return (ag);
}


/**
 * cst_getinput - ftn that gets line without new line.
 * @info: Parameter structure.
 * Return: Read bytes.
 */

ssize_t cst_getinput(pssdinfo *info)
{
	static char *buff;
	static size_t es, ds, len;
	ssize_t dc = 0;
	char **buf_p = &(info->arg), *p;

	myput_char(BUF_FLUSH);
	dc = input_buf(info, &buff, &len);
	if (dc == -1)
		return (-1);
	if (len)
	{
		ds = es;
		p = buff + es;

		check_chain(info, buff, &ds, es, len);
		while (ds < len)
		{
			if (is_chain(info, buff, &ds))
				break;
			ds++;
		}

		es = ds + 1;
		if (es >= len)
		{
			es = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (cststr_len(p));
	}

	*buf_p = buff;
	return (dc);
}

/**
 * read_buf - ftn that reads a buffer.
 * @info: struct parameter.
 * @buf: Buffer.
 * @i: Buffer size.
 * Return: Size r.
 */

ssize_t read_buf(pssdinfo *info, char *buf, size_t *i)
{
	ssize_t ko = 0;

	if (*i)
		return (0);
	ko = read(info->readfd, buf, READ_BUF_SIZE);
	if (ko >= 0)
		*i = ko;
	return (ko);
}

/**
 * cstget_line - ftn that will get next line of user input from STDIN.
 * @info: Parameter structure.
 * @ptr: Pointer to address of buffer, preallocated or NULL.
 * @length: Size of preallocated ptr buffer if not empty.
 * Return: so.
 */

int cstget_line(pssdinfo *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	char *re = NULL, *nptr = NULL, *c;
	size_t ke, pe;
	static size_t len;
	ssize_t gf = 0, so = 0;

	re = *ptr;

	if (re && length)
		so = *length;
	if (pe == len)
		pe = len = 0;

	gf = read_buf(info, buf, &len);

	if (gf == -1 || (gf == 0 && len == 0))
		return (-1);

	c = cststr_char(buf + pe, '\n');

	ke = c ? 1 + (unsigned int)(c - buf) : len;

	nptr = cstrealloc(pe, so, so ? so + ke : ke + 1);

	if (!nptr)
		return (re ? free(pe) -1 : -1);

	if (so)
		cststrn_cat(nptr, buf + pe, ke - pe);
	else
		cststrn_cpy(nptr, buf + pe, ke - pe + 1);

	so += ke - pe;
	pe = ke;
	re = nptr;

	if (length)
		*length = so;
	*ptr = re;
	return (so);
}

/**
 * sigintHandler - ftn that handles ctrl-C.
 * @sig_num: signal key.
 * Return: no return-(Void).
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
	cst_puts("\n");
	cst_puts("$ ");
	myput_char(BUF_FLUSH);
}
