#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - task 11
 * @n : variable to declare
 * Description: function that prints all natural numbers from n to 98
 * Return: always
 */
void print_to_98(int n)
{
	while (n < 98)
	{
		printf("%d, ", n);
		n++;
	}
	while (n > 98)
	{
		printf("%d, ", n);
		n--;
	}
	printf("%d\n", n);
}
