#include "main.h"
/**
 * puts2 - task 06
 * @str : Variable char to validate
 * Description:  function that prints every other character of a string
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
