#include "main.h"
/**
 * print_alphabet - 'prints the alphabet'
 *
 * Description: 'the program's description'
 *
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	int c = 97;

	while (c <= 122)
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
}
