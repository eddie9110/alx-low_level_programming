#include "shell.h"

/**
 * cst_iscmd - ftn that checks if file is executable.
 * @info: Info structure.
 * @path: File's path.
 * Return: 1 if true, else 0.
 */

int cst_iscmd(pssdinfo *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * cst_dupchars - a ftn that duplicates characters.
 * @pathstr: Path string.
 * @start: Starting index.
 * @stop: Stopping index.
 * Return: Pointer to the new buffer.
 */

char *cst_dupchars(char *pathstr, int start, int stop)
{
	static char bfr[1024];
	int pl, yg = 0;

	for (pl = 0, yg = start; yg < stop; yg++)
		if (pathstr[yg] != ':')
			bfr[pl++] = pathstr[yg];

	bfr[pl] = 0;

	return (bfr);
}

/**
 * cst_findpth - a ftn that finds commmand in the PATH string.
 * @info: Info struct.
 * @pathstr: the PATH string.
 * @cmd: the command to be searched for.
 * Return: Complete path of command if found (success), else NULL (failure).
 */

char *cst_findpth(pssdinfo *info, char *pathstr, char *cmd)
{
	char *path;
	int df = 0, curr_pos = 0;


	if (!pathstr)
		return (NULL);
	if ((cststr_len(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (cst_iscmd(info, cmd))
			return (cmd);
	}

	while (1)
	{
		if (!pathstr[df] || pathstr[df] == ':')
		{
			path = cst_dupchars(pathstr, curr_pos, df);
			if (!*path)
				cststr_cat(path, cmd);
			else
			{
				cststr_cat(path, "/");
				cststr_cat(path, cmd);
			}

			if (cst_iscmd(info, path))
				return (path);

			if (!pathstr[df])
				break;

			curr_pos = df;
		}
		df++;
	}
	return (NULL);
}
