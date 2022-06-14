#include "main.h"
/**
 * more_numbers - task 05
 * Description: function that prints 10 times the numbers, from 0 to 14
 * Return: always
 */
void more_numbers(void)
{
	int i, j, dig1, dig2;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j >= 10)
			{
				dig1 = j / 10;
				dig2 = j % 10;
				_putchar(dig1 + 48);
				_putchar(dig2 + 48);
			}
			else
			{
				_putchar(j + 48);
			}

		}
		_putchar(10);
	}
}
