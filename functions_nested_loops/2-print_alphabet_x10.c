#include "main.h"
/**
 * print_alphabet_x10 - 'Prints the alphabet'
 *
 * Return: Always 0 (Success)
 */
void print_alphabet_x10(void)
{
	int i = 0;
	char c = 97;

	while (i < 10)
	{
		c = 97;
		while (c <= 122)
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		i++;
	}
}
