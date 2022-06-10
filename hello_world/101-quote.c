#include <stdio.h>
/**
 * main - Entry point
 * Description: ' program that prints exactly phrasal'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int cadena[58] = {'a', 'n', 'd', ' ', 't', 'h', 'a', 't', ' ', 'p', 'i'
			  , 'e', 'c', 'e', ' ', 'o', 'f', ' ', 'a', 'r', 't'
			  , ' ', 'i', 's', ' ', 'u', 's', 'e', 'f', 'u', 'l'
			  , '"', ' ', '-', ' ', 'D', 'o', 'r', 'a', ' ', 'K'
			  , 'o', 'r', 'p', 'a', 'r', ',', ' ', '2', '0', '1'
			  , '5', '-', '1', '0', '-', '1', '9'};
	int i = 0;

	while (i < 58)
	{
		putchar(cadena[i]);
		i = i + 1;
	}
	putchar('\n');
	return (1);
}
