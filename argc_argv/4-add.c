#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - task 04
 * @argc : "argument count"
 * @argv : "argument vector"
 * Description: Write a program that adds positive numbers.
 * Return: always
 */
int main(int argc, char *argv[])
{
	int i, sum;

	if (argc == 1)
	{
		sum = 0;
	}

	for (i = 1; i < argc; i++)
	{
		if (atoi(argv[i]) > 0)
		{
			sum += atoi(argv[i]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%d\n", sum);
	return (0);
}
