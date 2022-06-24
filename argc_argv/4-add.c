#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
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
	int i, sum, csum = 0;

	if (argc == 1)
	{
		sum = 0;
	}

	for (i = 1; argv[i] != NULL; i++)
	{
		if (int_validation(argv[i]) == 1)
		{
			sum += atoi(argv[i]);
			csum++;
		}
	}
	if (csum == (argc - 1))
		printf("%d\n", sum);
	else
		printf("Error\n");
	return (0);
}

/**
 * int_validation - task 04
 * @s : "argument char"
 * Description: Write a program that adds positive numbers.
 * Return: always
 */
int int_validation(const char *s)
{
	/* Convert*/
	int val, base = 0, resint;  /* Use 10 for base 10 only input*/
	char *endptr;

/* If leading space not OK*/
/* isspace() only valid in unsigned char range and EOF.*/
	if (isspace((unsigned char) *s))
	{
		resint = 5;
		return (resint); /*Fail - leading spaces*/
	}
	errno = 0;
	val = strtol(s, &endptr, base);

	if (s == endptr)
	{ /* When endptr is same as s, no conversion happened.*/
		resint = 5;
		return (resint);/*"Fail - no conversion"*/
	}
/* detect overflow*/
	if (errno == ERANGE || val < INT_MIN || val > INT_MAX)
	{
		resint = 5;
		return (resint);/*"Fail - overflow"*/
	}
/* If trailing space OK, seek pass them*/
	while (isspace((unsigned char) *endptr))
	{
		endptr++;
	}
/* If trailing non-numeric text bad*/
	if (*endptr)
	{
		resint = 5;
		return (resint);/*"Fail - overflow"*/
	}
	/*printf("Success %d\n", (int) val);*/
	resint = 1;
	return (resint);
}
