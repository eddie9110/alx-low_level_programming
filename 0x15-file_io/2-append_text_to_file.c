#include "main.h"

/**
 * append_text_to_file - ftn that will append text to a file
 * @filename: the name of file of inerest
 * @text_content: content to append to file
 * Return: -1 on failure, else 1
 */


int append_text_to_file(const char *filename, char *text_content)
{
	int lgth = 0;
	int apn = 0;
	int al = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[lgth])
			lgth++;
	}

	apn = open(filename, O_WRONLY | O_APPEND);
	al = write(apn, text_content, lgth);

	if (apn == -1 || al == -1)
		return (-1);

	close(apn);

	return (1);
}
