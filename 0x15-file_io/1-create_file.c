#include <stddef.h>
#include "main.h"

/**
 * create_file - ftn that creates a file
 * @filename: the name of file to be created
 * @text_content: pointer to content to be put in file
 * Return: 1 or -1 for failure
 */

int create_file(const char *filename, char *text_content)
{
	int xa = 0;
	int lgth = 0;
	int wrte = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lgth = 0; text_content[lgth];)
			lgth++;
	}

	xa = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wrte = write(xa, text_content, lgth);

	if (xa == -1 || wrte == -1)
		return (-1);

	close(xa);

	return (1);
}
