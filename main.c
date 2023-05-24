#include "shell.h"

/**
 * main - Starting point.
 * @agc: Argument count.
 * @agv: Argument vector.
 * Return: 0 on success or 1 on failure.
 */

int main(int agc, char **agv)
{
	pssdinfo info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (agc == 2)
	{
		fd = open(agv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);

			if (errno == ENOENT)
			{
				cstaputs(agv[0]);
				cstaputs(": 0: Unable to open ");
				cstaputs(agv[1]);
				cstaputchar('\n');
				cstaputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	cstgenenv_list(info);

	cstreadhist(info);
	hsh(info, agv);
	return (EXIT_SUCCESS);
}
