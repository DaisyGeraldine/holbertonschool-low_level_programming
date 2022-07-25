#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
/**
 * main - task 03
 * @ac : "argument count"
 * @av : "argument vector"
 * Description: Write a program that copies the
 * content of a file to another file.
 * Return: always
 */
int main(int ac, char **av)
{
	int fromfd = 0, tofd = 0, bytes_read = 0, _EOF = 1, fdw;
	char buffer[1024];

	if (ac != 3)
		messagges_Error(97, NULL, 0);
	fromfd = open(av[1], O_RDONLY);
	if (fromfd == -1)
		messagges_Error(98, av[1], fromfd);
	tofd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (tofd == -1)
	{
		safe_close(fromfd);
		messagges_Error(99, av[2], tofd);
	}
	while (_EOF)
	{
		_EOF = read(fromfd, buffer, 1024);
		if (_EOF == -1)
		{
			safe_close(fromfd);
			safe_close(tofd);
			messagges_Error(98, av[1], _EOF);
		}
		if (_EOF > 0)
		{
			bytes_read += EOF;
			fdw = write(tofd, buffer, _EOF);
			if (fdw == -1)
			{
				safe_close(fromfd);
				safe_close(tofd);
				messagges_Error(99, av[2], fdw);
			}
		}
		else if (_EOF == 0)
			break;
	}
	safe_close(tofd);
	safe_close(fromfd);
	return (0);
}

/**
 * messagges_Error - task 03
 * @codError : Codig Error
 * @file : Name of the file
 * @filedes : file descriptor
 * Description: prints message Error, exit (cod);
 * Return: void
 */
int messagges_Error(int codError, char *file, int filedes)
{
	switch (codError)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(codError);
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(codError);
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(codError);
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filedes);
		exit(codError);
	default:
		return (0);
	}
}
/**
 * safe_close - task 03
 * @filedes : file descriptor
 * Description: close file
 * Return: void
 */
int safe_close(int filedes)
{
	int error;

	error = close(filedes);
	if (error == -1)
		messagges_Error(100, NULL, filedes);

	return (error);
}
