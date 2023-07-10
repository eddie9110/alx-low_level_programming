#include <stddef.h>
#include "main.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * create_file - a ftn that makes a file
 * @filename: parameter represents a ptr to the file name of the created file
 * @text_content: a ptr to a string to be written to file
 * Return: fail (-1), success (1)
 */

int create_file(const char *filename, char *text_content)
{
	int pdown = 0;
	int gl = 0;
	int lnge = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lnge = 0; text_content[lnge];)
			lnge++;
	}

	gl = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	pdown = write(gl, text_content, lnge);

	if (gl == -1 || pdown == -1)
		return (-1);


	close(gl);


	return (1);
}
