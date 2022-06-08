#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'Shows single digit numbers to 10'
 *
 * Return: Always 0 (Success)
 */
int main(void)
{int ch = 48;
	while (ch <= 57)
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
