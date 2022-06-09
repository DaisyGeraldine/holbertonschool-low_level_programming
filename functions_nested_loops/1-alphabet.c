#include "main.h"
/**
 * main - 1-alphabet.c
 *
 * Description: 'Prints _putchar, followed by a new line'
 *
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	int c;

	for (c = 97; c <= 122; c++)
	{
		_putchar(c);
	}
	_putchar(10);
}
