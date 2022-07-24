#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
/**
 * append_text_to_file - task 02
 * @filename : string of the filename
 * @text_content : string text content
 * Description: function that appends text at the end of a file.
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd = 0;
	ssize_t fdw = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	fdw = write(fd, text_content, strlen(text_content));

	if (fdw != (int)strlen(text_content))
	{
		perror("Error writing the file");
		return (EXIT_FAILURE);
	}

	if (fdw == -1)
		return (-1);

	close(fd);
	return (1);
}
