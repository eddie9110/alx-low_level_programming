#include "shell.h"

/**
 * cst_myexit - ftn that exits the shell.
 * @info: Structure containing possible arguments.
 *  Return: Exits with a given exit status.
 */

int cst_myexit(pssdinfo *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = cst_erratoi(info->argv[1]);

		if (exitcheck == -1)
		{
			info->status = 2;
			cstprinterror(info, "Wrong number: ");
			cstaputs(info->argv[1]);
			cstaputchar('\n');
			return (1);
		}
		info->err_num = cst_erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * cstmycd - ftn to change the current working directory.
 * @info: Structure containing possible arguments.
 *  Return: 0
 */
int cstmycd(pssdinfo *info)
{
	char *se, *dirc, buffer[1024];
	int chdir_ret;

	se = getcwd(buffer, 1024);
	if (!se)
		cst_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dirc = cstget_env(info, "HOME=");
		if (!dirc)
			chdir_ret = chdir((dirc = cstget_env(info, "PWD=")) ? dirc : "/");
		else
			chdir_ret = chdir(dirc);
	}
	else if (cststr_cmp(info->argv[1], "-") == 0)
	{
		if (!cstget_env(info, "OLDPWD="))
		{
			cst_puts(se);
			myput_char('\n');
			return (1);
		}
		cst_puts(cstget_env(info, "OLDPWD=")), myput_char('\n');
		chdir_ret = chdir((dirc = cstget_env(info, "OLDPWD=")) ? dirc : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		cstprinterror(info, "Cannot change directory to ");
		cstaputs(info->argv[1]), cstaputchar('\n');
	}

	else
	{
		cstset_env(info, "OLDPWD", cstget_env(info, "PWD="));
		cstset_env(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * cst_myhelp - ftn to display help.
 * @info: Structure containing possible arguments.
 *  Return: Always 0.
 */

int cst_myhelp(pssdinfo *info)
{
	char **arg_array;

	arg_array = info->argv;
	cst_puts("Help for this function does not exist \n");
	if (0)
		cst_puts(*arg_array);

	return (0);
}
