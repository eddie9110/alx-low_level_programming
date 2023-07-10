#include "main.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * append_text_to_file - a ftn that appends text to existing text in a file
 * @filename: the name of file to append to
 * @text_content: the text to append to the file content
 * Return: 1 on success, -1 if filename is NULL,
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int twofd = 0;
	int fb = 0;
	int lgne = 0;


	if (filename == NULL) /* error handling */
		return (-1);


	if (text_content != NULL)
	{
		while (text_content[lgne])
			lgne++;
	}

	twofd = open(filename, O_WRONLY | O_APPEND);
	fb = write(twofd, text_content, lgne);

	if (twofd == -1 || fb == -1)
		return (-1);

	close(twofd);
	return (1);
}
