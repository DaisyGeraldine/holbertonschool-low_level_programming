#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'prints all the numbers of base 16 in lowercase'
 *
 * Return: Always 0 (Success)
 */
int main(void)
{char ch = '0';
	while (ch <= '9')
	{
		putchar(ch);
		ch++;
	}
	ch = 'a';
	while (ch <= 'f')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
