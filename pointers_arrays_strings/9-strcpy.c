#include "main.h"
/**
 * _strcpy- task 09
 * @dest : variable char
 * @src : variable char
 * Description: function that copies the string pointed to by src
 * Return: always
 */
char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	return (aux);
}
