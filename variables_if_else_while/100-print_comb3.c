#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'Prints all possible different combinations of two digits'
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 48, j = 49, e = 32, c = 44;

	while (i <= 57)
	{
		j = i + 1;
		while (j <= 57)
		{
			putchar(i);
			putchar(j);
			if (i != 56)
			{
				putchar(c); /*coma */
				putchar(e); /*espacio*/
			}
			j++;
		}
		i++;
	}
	putchar('\n');
	return (0);
}
