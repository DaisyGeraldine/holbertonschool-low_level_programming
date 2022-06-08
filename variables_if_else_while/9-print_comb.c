#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'Shows numbers of 0 to 9'
 *
 * Return: Always 0 (Success)
 */
int main(void)
{int i = 48, e = 32, c = 44;
	while (i <= 57)
	{
		putchar(i);
		if (i != 57)
		{
			putchar(c); /*coma */
			putchar(e); /*espacio*/
		}
		i++;
	}
	putchar('\n');
	return (0);
}
