#include "main.h"
/**
 * print_numbers - task 03
 * Description:  function that prints the numbers, from 0 to 9
 * Return: always
 */
void print_numbers(void)
{
	int i;

	for (i = 0 ; i < 10 ; i++)
	{
		_putchar(i + 48);
	}
	_putchar(10);
}
