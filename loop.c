#include "shell.h"

/**
 * hsh - ftn that is the main loop of shell.
 * @info: Parameter, return info structure.
 * @agv: Argument vector.
 * Return: 0 on success, 1 on error.
 */

int hsh(pssdinfo *info, char **agv)
{
	ssize_t yt = 0;
	int bltn_ret = 0;

	while (yt != -1 && bltn_ret != -2)
	{
		clear_info(info);
		if (cst_intrctive(info))
			cst_puts("$ ");

		cstaputchar(BUF_FLUSH);

		yt = cst_getinput(info);

		if (yt != -1)
		{
			set_info(info, agv);
			bltn_ret = cstfndbuiltin(info);
			if (bltn_ret == -1)
				cstfndcmd(info);
		}
		else if (cst_intrctive(info))
			myput_char('\n');
		free_info(info, 0);
	}

	cstwritehist(info);

	free_info(info, 1);

	if (!cst_intrctive(info) && info->status)
		exit(info->status);

	if (bltn_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}

	return (bltn_ret);
}

/**
 * cstfndbuiltin - ftn that finds a built-in command.
 * @info: Parameter, return info structure.
 * Return: -2 if builtin cmd signals exit()
 * -1 if builtin cmd wasn't found,
 *	0 if builtin cmd executed successfully,
 *	1 if builtin cmd failed to execute.
 */

int cstfndbuiltin(pssdinfo *info)
{
	int uy, built_in_ret = -1;
	bltin_tble builtintbl[] = {
		{"exit", cstmyexit},
		{"env", cstprt_env},
		{"help", cstmyhelp},
		{"history", cst_histlst},
		{"setenv", cstset_env},
		{"unsetenv", cstunset_env},
		{"cd", cstmycd},
		{"alias", cst_alias},
		{NULL, NULL}
	};

	for (uy = 0; builtintbl[uy].type; uy++)
		if (cststr_cmp(info->argv[0], builtintbl[uy].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[uy].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * cstfndcmd - ftn that finds a command in path.
 * @info: struct arameter.
 * Return: Void.
 */

void cstfndcmd(pssdinfo *info)
{
	char *pth = NULL;
	int uy, gt;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (uy = 0, gt = 0; info->arg[uy]; uy++)
		if (!cstisdelim(info->arg[uy], " \t\n"))
			gt++;
	if (!gt)
		return;

	pth = cst_findpath(info, cstget_env(info, "PATH="), info->argv[0]);
	if (pth)
	{
		info->path = pth;
		cstforkcmd(info);
	}
	else
	{
		if ((cst_intrctive(info) || cstget_env(info, "PATH=")
			|| info->argv[0][0] == '/') && cst_iscmd(info, info->argv[0]))
			cstforkcmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			cstprinterror(info, "not found\n");
		}
	}
}

/**
 * cstforkcmd - ftn that forks an executable thread for cmd.
 * @info: Parameter,return info structure.
 * Return: Void.
 */

void cstforkcmd(pssdinfo *info)
{
	pid_t fkrtn;

	fkrtn = fork();
	if (fkrtn == -1)
	{
		perror("Forking error:");
		return;
	}
	if (fkrtn == 0)
	{
		if (execve(info->path, info->argv, cstget_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				cstprinterror(info, "Access denied\n");
		}
	}
}
