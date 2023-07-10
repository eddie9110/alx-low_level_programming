#include <stdlib.h>
#include "main.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * read_textfile - a ftn that reads the contents of a file to std output
 * @filename: name of file of interest
 * @letters: no. of bytes to be read to stdout
 * Return: spc - no. of bytes read and printed or 0 upon failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t poi;
	char *oplk;
	ssize_t spc;
	ssize_t fhndlr;


	fhndlr = open(filename, O_RDONLY);

	if (fhndlr == -1)
		return (0);

	else
	{
		oplk = malloc(sizeof(char) * letters);
		poi = read(fhndlr, oplk, letters);
		spc = write(STDOUT_FILENO, oplk, poi);
	} free(oplk);


	close(fhndlr);

	return (spc);
}
