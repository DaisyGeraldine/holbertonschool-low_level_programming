#include <stdio.h>
#include "main.h"
/**
 * main - task 01
 * @argc : "argument count"
 * @argv : "argument vector"
 * Description: Write a program that prints number of arguments passed into it
 * Return: always
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
