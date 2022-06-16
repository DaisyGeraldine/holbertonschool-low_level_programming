#include "main.h"
/**
 * puts_half - task 07
 * @str : Variable char to validate
 * Description:  function that prints half of a string, followed by a new line
 * Return: always
 */
void puts_half(char *str)
{
	int i = 0, j;

	while (str[i] != '\0')
		i++;
	if (i % 2 != 0)
		i = (i / 2) + 1;
	else
		i = i / 2;

	for (j = i; str[j] != '\0'; j++)
	{
		_putchar(str[j]);
	}
	_putchar(10);
}
