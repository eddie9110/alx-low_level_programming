#include "shell.h"

/**
 *cstaputs - ftn to prints an input string.
 * @str: String to be printed.
 * Return: no return (void).
 */

void cstaputs(char *str)
{
	int yt = 0;

	if (!str)
		return;

	while (str[yt] != '\0')
	{
		cstaputchar(str[yt]);
		yt++;
	}
}

/**
 * cstaputchar - Writes the character c.
 * @c: Character to print.
 * Return: 1 for success, else -1.
 */

int cstaputchar(char c)
{
	static int io;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || io >= WRITE_BUF_SIZE)
	{
		write(2, buf, io);
		io = 0;
	}
	if (c != BUF_FLUSH)
		buf[io++] = c;
	return (1);
}

/**
 * cstputfd - a ftn that writes character c to given fd.
 * @c: Character to print.
 * @fd: File descriptor to write to.
 * Return: On success 1, else -1.
 */

int cstputfd(char c, int fd)
{
	static int xo;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || xo >= WRITE_BUF_SIZE)
	{
		write(fd, buf, xo);
		xo = 0;
	}
	if (c != BUF_FLUSH)
		buf[xo++] = c;
	return (1);
}

/**
 *cstputinfd - a ftn that prints an input string.
 * @str: the string that will be printed.
 * @fd: the file descriptor.
 * Return: (we)-No. of characters.
 */

int cstputinfd(char *str, int fd)
{
	int we = 0;

	if (!str)
		return (0);
	while (*str)
	{
		we += cstputfd(*str++, fd);
	}
	return (we);
}
