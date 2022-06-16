#include "main.h"
/**
 * print_rev - task 04
 * @s : Variable char to validate
 * Description: function that prints a string, in reverse
 * Return: always
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0)
			_putchar(str[i]);
	}
	_putchar(10);
}
