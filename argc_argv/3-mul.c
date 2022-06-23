#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - task 03
 * @argc : "argument count"
 * @argv : "argument vector"
 * Description: Write a program that multiplies two numbers.
 * Return: always
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int mul = 0;

	if (argc > 2)
	{
		mul = atoi(argv[1]) * atoi(argv[2]);
		printf("%d\n", mul);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
