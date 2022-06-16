#include "main.h"
/**
 * print_rev - task 04
 * @s : Variable char to validate
 * Description: function that prints a string, in reverse
 * Return: always
 */
void print_rev(char *s)
{
	int i = 0, j;

	while (s[i] != '\0')
		i++;
	i = i - 1;

	for (j = i ; j >= 0; j--)
	{
		_putchar(s[j]);
	}
	_putchar(10);
}
