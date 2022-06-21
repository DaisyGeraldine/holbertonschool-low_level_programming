#include "main.h"
/**
 * _puts_recursion - task 00
 * @s : Variable char to validate
 * Description:  function that prints a string, followed by a new line
 * Return: always
 */
void _puts_recursion(char *s)
{


	if (*s == '\0')
	{
		_putchar(10);
		return;
	}

	_putchar(*s);
	_puts_recursion(s + 1);
	/*return (_putchar(10));*/
}
