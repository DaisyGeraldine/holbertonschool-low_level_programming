#include "main.h"
/**
 * _memset - task 00
 * @s : Variable char to validate
 * @b : Variable char to validate
 * @n : quantity in bytes
 * Description: function that fills memory with a constant byte
 * Return: always
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int h;

	for (h = 0; h < n; h++)
		s[h] = b;
	return (s);
}
