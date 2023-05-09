#include <stddef.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - ftn to read file contents
 * @filename: file to be read
 * @letters: no. of letters to be printed
 * Return: no. of letters to be read and printed to stdout
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *dspace;
	ssize_t fprtr;
	ssize_t byt;
	ssize_t ay;

	fprtr = open(filename, O_RDONLY);

	if (fprtr == -1)
		return (0);

	dspace = malloc(sizeof(char) * letters);
	ay = read(fprtr, dspace, letters);
	byt = write(STDOUT_FILENO, dspace, ay);

	free(dspace);


	close(fprtr);

	return (byt);
}
