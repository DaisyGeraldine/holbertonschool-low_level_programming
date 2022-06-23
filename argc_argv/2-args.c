#include <stdio.h>
#include "main.h"
/**
 * main - task 02
 * @argc : "argument count"
 * @argv : "argument vector"
 * Description: Write a program that prints all arguments it receives.
 * Return: always
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
