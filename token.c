#include "shell.h"

/**
 * **cststrtow - ftn that splits a string into separate words.
 * @str: Input string.
 * @d: Delimeter string.
 * Return: Pointer to an array of strings, or NULL on error.
 */

char **cststrtow(char *str, char *d)
{
	int ai, jp, kt, m, nofwords = 0;
	char **ts;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";

	for (ai = 0; str[ai] != '\0'; ai++)
		if (!cstisdelim(str[ai], d) && (cstisdelim(str[ai + 1], d) || !str[ai + 1]))
			nofwords++;

	if (nofwords == 0)
		return (NULL);

	ts = malloc((1 + nofwords) * sizeof(char *));

	if (!ts)
		return (NULL);
	for (ai = 0, jp = 0; jp < nofwords; jp++)
	{
		while (cstisdelim(str[ai], d))
			ai++;
		kt = 0;
		while (!cstisdelim(str[ai + kt], d) && str[ai + kt])
			kt++;
		ts[jp] = malloc((kt + 1) * sizeof(char));
		if (!ts[jp])
		{
			for (kt = 0; kt < jp; kt++)
				free(ts[kt]);
			free(ts);
			return (NULL);
		}
		for (m = 0; m < kt; m++)
			ts[jp][m] = str[ai++];
		ts[jp][m] = 0;
	}
	ts[jp] = NULL;
	return (ts);
}

/**
 * **cststrtow2 - a ftn that splits a string.
 * @str: Input string.
 * @d: a delimeter.
 * Return: Pointer to an array of strings or NULL on error.
 */

char **cststrtow2(char *str, char d)
{
	char **sf;
	int oi, tr, pk, hm, nofwords = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (oi = 0; str[oi] != '\0'; oi++)
		if ((str[oi] != d && str[oi + 1] == d) ||
		    (str[oi] != d && !str[oi + 1]) || str[oi + 1] == d)
			nofwords++;
	if (nofwords == 0)
		return (NULL);
/* */
	sf = malloc((1 + nofwords) * sizeof(char *));
	/* */
	if (!sf)
		return (NULL);

	for (oi = 0, tr = 0; tr < nofwords; tr++)
	{
		while (str[oi] == d && str[oi] != d)
			oi++;
		pk = 0;
		while (str[oi + pk] != d && str[oi + pk] && str[oi + pk] != d)
			pk++;
		sf[tr] = malloc((pk + 1) * sizeof(char));
		if (!sf[tr])
		{
			for (pk = 0; pk < tr; pk++)
				free(sf[pk]);
			free(sf);
			return (NULL);
		}
		for (hm = 0; hm < pk; hm++)
			sf[tr][hm] = str[oi++];
		sf[tr][hm] = 0;
	}
	sf[tr] = NULL;
	return (sf);
}
