#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
/**
 * create_file - task 01
 * @filename : string of the filename
 * @text_content : string text content
 * Description: function that creates a file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd = 0;
	ssize_t fdw;

	if (filename == NULL || text_content == NULL)
		return (-1);
    /* open a file for output              */
    /* replace existing file if it exists  */
    /* with read/write perms for owner     */
	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);

	if (fd == -1)
		return (-1);

	fdw = write(fd, text_content, strlen(text_content));

	if (fdw != (int)strlen(text_content))
	{
		perror("Error writing myfile.dat");
		return (EXIT_FAILURE);
	}

	if (fdw == -1)
		return (-1);

	close(fd);
	return (1);
}
