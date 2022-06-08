#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'Prints all possible different combinations of three digits'
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 48, j = 49, k = 50, e = 32, c = 44;

	while (i <= 57)
	{
		j = i + 1;
		while (j <= 57)
		{
			k = j + 1;
			while (k <= 57)
			{
				putchar(i);
				putchar(j);
				putchar(k);
				if (i != 55)
				{
					putchar(c); /*coma */
					putchar(e); /*espacio*/
				}
				k++;
			}
			j++;
		}
		i++;
	}
	putchar('\n');
	return (0);
}
