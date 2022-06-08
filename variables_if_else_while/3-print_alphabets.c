#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'Alphabet in lowercase, and then in uppercase'
 *
 * Return: Always 0 (Success)
 */
int main(void)
{char ch = 'a';
	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	ch = 'A';
	while (ch <= 'Z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
