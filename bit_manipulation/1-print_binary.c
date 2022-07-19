#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_binary - task 01
 * @n : number binary
 * Description: function that prints the binary representation of a number.
 * Return: 0
 */
void print_binary(unsigned long int n)
{
	unsigned int i, cont = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = 1 << 31; i > 0; i = i / 2)
		if (n & i)
		{
			_putchar('1');
			cont = 1;
		}
		else if (cont == 1)
		{
			_putchar('0');
		}
}
