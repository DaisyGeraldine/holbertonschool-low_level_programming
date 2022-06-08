#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'Shows single digit numbers to 10'
 *
 * Return: Always 0 (Success)
 */
int main(void)
{unsigned char ch = '0';
	while (ch <= '9')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
