#include "shell.h"

/**
 * cststr_len - ftn that returns length of a string.
 * @s: string of interest.
 * Return: length of string.
 */

int cststr_len(char *s)
{
	int jo = 0;

	if (!s)
		return (0);

	while (*s++)
		jo++;
	return (jo);
}

/**
 * cststr_cmp - a ftn that does a lexicogarphic comparison for 2 strings.
 * @s1: string one.
 * @s2: string two.
 * Return: 0 if s1 == s2 or -ve no. if s1 < s2 or +ve no. if s1 > s2,
 */

int cststr_cmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - ftn to check if needle starts with haystack.
 * @strsrch: String to search.
 * @strfnd: Substring to find.
 * Return: Memory address of next character of haystack or NULL.
 */

char *starts_with(const char *strsrch, const char *strfnd)
{
	while (*strfnd)
		if (*strfnd++ != *strsrch++)
			return (NULL);
	return ((char *)strsrch);
}

/**
 * cststr_cat - ftn that concatenates 2 strings.
 * @dst: Destination buffer.
 * @srce: Source buffer.
 * Return: Pointer to destination buffer.
 */

char *cststr_cat(char *dst, char *srce)
{
	char *ret = dst;

	while (*dst)
		dst++;
	while (*srce)
		*dst++ = *srce++;
	*dst = *srce;
	return (ret);
}
