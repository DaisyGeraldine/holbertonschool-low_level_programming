#include "main.h"
/**
 * times_table - task 09
 * Description: function that prints the 9 times table
 * Return: always
 */
void times_table(void)
{
	int c1, c2, r, d1, d2;

	c1 = 0, c2 = 0;

	while (c1 <= 9)
	{
		c2 = 1;
		_putchar(48);
		while (c2 <= 9)
		{
			r = c2 * c1;
			d1 = r / 10;
			d2 = r % 10;
			if (c2 >= 0 && c2 < 10)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (r <= 9)
			{
				_putchar(32);
				_putchar(d2 + 48);
			}
			else
			{
				_putchar(d1 + 48);
				_putchar(d2 + 48);
			}
			c2++;
		}
		_putchar('\n');
		c1++;
	}
}
