#include "shell.h"

/**
 * cst_erratoi - ftn that converts a string to an int.
 * @s: String to be converted.
 * Return: Converted integers or 0 if no numbers in string.
 */

int cst_erratoi(char *s)
{
	int ai = 0;
	unsigned long int rslt = 0;

	if (*s == '+')
		s++;

	for (ai = 0;  s[ai] != '\0'; ai++)
	{
		if (s[ai] >= '0' && s[ai] <= '9')
		{
			rslt *= 10;
			rslt += (s[ai] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}

		else
			return (-1);
	}
	return (rslt);
}

/**
 * cstprinterror - ftn that prints error messages.
 * @info: a struct parameter.
 * @estr: String with specified error.
 * Return: Converted string.
 */

void cstprinterror(pssdinfo *info, char *estr)
{
	cstaputs(info->fname);
	cstaputs(": ");
	cstprintdec(info->line_count, STDERR_FILENO);
	cstaputs(": ");
	cstaputs(info->argv[0]);
	cstaputs(": ");
	cstaputs(estr);
}

/**
 * cstprintdec - a ftn that prints a decimal no.
 * @input: Input.
 * @fd: Filedescriptor.
 * Return: Total number of integers printed.
 */

int cstprintdec(int input, int fd)
{
	int (*__putchar)(char) = myput_char;
	int xi, cnt = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = cstaputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		cnt++;
	}

	else
		_abs_ = input;
	current = _abs_;

	for (xi = 1000000000; xi > 1; xi /= 10)
	{
		if (_abs_ / xi)
		{
			__putchar('0' + current / xi);
			cnt++;
		}
		current %= xi;
	}
	__putchar('0' + current);
	cnt++;

	return (cnt);
}

/**
 * cstconvnumb - a ftn that works similar to itoa.
 * @num: Number.
 * @base: Base of number.
 * @flags: reps flag argument.
 * Return: A string - (success).
 */

char *cstconvnumb(long int num, int base, int flags)
{
	static char *ary;
	char *potr;
	unsigned long ne = num;
	static char buff[50];
	char sgn = 0;


	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		ne = -num;
		sgn = '-';
	}

	ary = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	potr = &buff[49];
	*potr = '\0';

	do	{
		*--potr = ary[ne % base];
		ne /= base;
	} while (ne != 0);

	if (sgn)
		*--potr = sgn;
	return (potr);
}

/**
 * cstrmvcomments - a ftn that replaces the first occurence of '#' with '\0'.
 * @buf: reps the memory address of the string to be modified.
 * Return: no return (void).
 */

void cstrmvcomments(char *buf)
{
	int ax;

	for (ax = 0; buf[ax] != '\0'; ax++)
	{
		if (buf[ax] == '#' && (!ax || buf[ax - 1] == ' '))
		{
			buf[ax] = '\0';
			break;
		}
	}
}
