#include "main.h"
/**
 * _print_rev_recursion - task 00
 * @s : Variable char to validate
 * Description: function that prints a string in reverse
 * Return: always
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar(10);
		return;
	}

	_print_rev_recursion(s + 1);
	_putchar(*s);
}
