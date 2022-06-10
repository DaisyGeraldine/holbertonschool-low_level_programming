#include "main.h"
/**
 * jack_bauer - task 08
 * Description: function that prints every minute of the day of Jack Bauer
 * Return: always
 */
void jack_bauer(void)
{
	int m = 48, s = 48, h1 = 48, h2 = 48;

	while (h1 <= 50)
	{
		h2 = 48;
		while (h2 <= 57)
		{
			if (h1 == 50 && h2 == 52)
			{
				break;
			}
			m = 48;
			while (m <= 53)
			{
				s = 48;
				while (s <= 57)
				{
					if (m == 53 && s == 58)
					{
						break;
					}
					_putchar(h1);
					_putchar(h2);
					_putchar(':');
					_putchar(m);
					_putchar(s);
					_putchar('\n');
					s++;
				}
				m++;
			}
			h2++;
		}
		h1++;
	}
}
