#include "shell.h"

/**
 * cstgethistfile - ftn that fetches the history file.
 * @info: Parameter structure.
 * Return: Allocated string containing the history file.
 */

char *cstgethistfile(pssdinfo *info)
{
	char *bfr, *dr;

	dr = cstget_env(info, "HOME=");

	if (!dr)
		return (NULL);

	bfr = malloc(sizeof(char) * (cststr_len(dr) + cststr_len(HIST_FILE) + 2));

	if (!bfr)
		return (NULL);

	bfr[0] = 0;

	cststr_cpy(bfr, dr);
	cststr_cat(bfr, "/");
	cststr_cat(bfr, HIST_FILE);

	return (bfr);
}


/**
 * cstwritehist - a ftn that creates or appends a file.
 * @info: Parameter structure.
 * Return: 1 on success, else -1.
 */

int cstwritehist(pssdinfo *info)
{
	ssize_t fd;
	str_lst *node = NULL;
	char *filename = cstgethistfile(info);


	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);

	free(filename);

	if (fd == -1)
		return (-1);

	for (node = info->history; node; node = node->next)
	{
		cstputinfd(node->str, fd);
		cstputfd('\n', fd);
	}
	cstputfd(BUF_FLUSH, fd);

	close(fd);

	return (1);
}


/**
 * cstreadhist - ftn that reads the history from a history file.
 * @info: Parameter structure.
 * Return: histcount on success, else 0.
 */

int cstreadhist(pssdinfo *info)
{
	int oe, last, linecnt = 0;
	struct stat st;
	ssize_t fd, rdlgth, fsize = 0;
	char *bfr = NULL, *filename = cstgethistfile(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;

	if (fsize < 2)
		return (0);
	bfr = malloc(sizeof(char) * (fsize + 1));
	if (!bfr)
		return (0);
	rdlgth = read(fd, bfr, fsize);
	bfr[fsize] = 0;
	if (rdlgth <= 0)
		return (free(bfr), 0);
	close(fd);
	for (oe = 0; oe < fsize; oe++)
		if (bfr[oe] == '\n')
		{
			bfr[oe] = 0;
			cst_buildhistlist(info, bfr + last, linecnt++);
			last = oe + 1;
		}
	if (last != oe)
		cst_buildhistlist(info, bfr + last, linecnt++);
	free(bfr);
	info->histcount = linecnt;
	while (info->histcount-- >= HIST_MAX)
		cstdeletenodeatindx(&(info->history), 0);
	cstrenmbhist(info);
	return (info->histcount);
}

/**
 * cst_buildhistlst - ftn that adds an entry to a history linked list.
 * @info: Structure containing possible arguments.
 * @buf: A buffer.
 * @linecount: histcount.
 * Return: Always 0.
 */

int cst_buildhistlst(pssdinfo *info, char *buf, int linecount)
{
	str_lst *node = NULL;

	if (info->history)
		node = info->history;
	cstaddnodeatend(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}


/**
 * cstrenmbhist - ftn that renumbers the history of the linked list changes.
 * @info: Structure containing possible arguments.
 * Return: New histcount.
 */

int cstrenmbhist(pssdinfo *info)
{
	str_lst *node = info->history;
	int ai = 0;

	while (node)
	{
		node->num = ai++;
		node = node->next;
	}

	return (info->histcount = ai);
}
