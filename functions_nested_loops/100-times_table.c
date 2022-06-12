#include "main.h"
/**
 * print_times_table - task 12
 * @n : number to validate
 * Description: function that prints the n times table, starting with 0
 * Return: always
 */
void print_times_table(int n)
{
	int c1 = 0, c2 = 0, r, d1, d2, d3;

	if (n <= 15)
	{
		for (; c1 <= n; c1++)
		{
			c2 = 1;
			_putchar(48);
			for (; c2 <= n; c2++)
			{
				r = c2 * c1;
				(r <= 99) ? (d1 = r / 10) : (d1 = r / 100);
				d2 = (r / 10) % 10;
				d3 = r % 10;
				if (c2 >= 0 && c2 <= 15)
				{
					_putchar(',');
					_putchar(' ');
				}
				if (r <= 9)
				{
					_putchar(32);
					_putchar(32);
				}
				else if (r > 9 && r <= 99)
				{
					_putchar(32);
					_putchar(d2 + 48);
				}
				else
				{
					_putchar(d1 + 48);
					_putchar(d2 + 48);
				}
				_putchar(d3 + 48);
			}
			_putchar('\n');
		}
	}
}
