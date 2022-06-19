#include "main.h"
/**
 * _strcmp - task 03
 * @s1 : First string
 * @s2 : Second string
 * Description: function that compares two strings
 * Return: always
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++, s2++;
	}
	return (0);
}
