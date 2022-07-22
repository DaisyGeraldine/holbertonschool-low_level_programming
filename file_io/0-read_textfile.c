#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
/**
 * read_textfile - task 00
 * @filename : string of the filename
 * @letters : number of letters
 * Description: function that reads a text file and prints it
 * to the POSIX standard output.
 * Return:  the actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fdo;
	ssize_t fdr, fdw;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
		return (0);

	fdo = open(filename, O_RDONLY);

	if (fdo < 0)
	{
		free(buffer);
		return (0);
	}

	fdr = read(fdo, buffer, letters);

	if (fdr < 0)
	{
		free(buffer);
		return (0);
	}

	fdw = write(STDOUT_FILENO, buffer, fdr);

	free(buffer);
	close(fdo);

	if (fdw < 0)
		return (0);

	return (fdw);
}
