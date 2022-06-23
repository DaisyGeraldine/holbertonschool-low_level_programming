#include <stdio.h>
#include "main.h"
/**
 * main - task 00
 * @argc : "argument count"
 * @argv : "argument vector"
 * Description: Write a program that prints its name
 * Return: always
 */
int main(int argc, char *argv[])
{
	printf("%s\n", argv[argc - 1]);
	return (0);
}
