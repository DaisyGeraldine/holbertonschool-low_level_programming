#include "main.h"
/**
 * _puts - task 03
 * @str : Variable char to validate
 * Description: function that prints a string
 * Return: always
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar(10);
}
