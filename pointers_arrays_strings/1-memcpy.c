#include "main.h"
/**
 * _memcpy - task 01
 * @dest : char destiny
 * @src : char source
 * @n : quantity in bytes
 * Description: function that copies memory area
 * Return: always
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ini = dest;

	while (n--)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return (ini);
}
