#include "shell.h"

/**
 * cst_intrctive - ftn that returns true if shell is in interactive mode.
 * @info: Structure address.
 * Return: 1 if interactive mode, 0 if not.
 */

int cst_intrctive(pssdinfo *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * cstisdelim - a ftn that looks for delimeters in an input string.
 * @c: Char to check.
 * @delim: Delimeter string.
 * Return: 1 if true, 0 if false.
 */

int cstisdelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *cst_isalpha - ftn to check for an alphabetic character.
 *@c: Character to input.
 *Return: 1 if alphabetic, else 0.
 */

int cst_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *cst_atoi - ftn to convert a string to an integer.
 *@s: String to convert.
 *Return: converted integers otpt.
 */

int cst_atoi(char *s)
{
	int qo, sgn = 1, flag = 0, otpt;
	unsigned int rsult = 0;

	for (qo = 0;  s[qo] != '\0' && flag != 2; qo++)
	{
		if (s[qo] == '-')
			sgn *= -1;

		if (s[qo] >= '0' && s[qo] <= '9')
		{
			flag = 1;
			rsult *= 10;
			rsult += (s[qo] - '0');
		}

		else if (flag == 1)
			flag = 2;
	}

	if (sgn == -1)
		otpt = -rsult;
	else
		otpt = rsult;

	return (otpt);
}
