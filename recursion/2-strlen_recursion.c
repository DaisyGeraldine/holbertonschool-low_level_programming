#include "main.h"
/**
 * _strlen_recursion - task 02
 * @s : cadena char
 * Description: function that returns the length of a string
 * Return: always
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + _strlen_recursion(s + 1));
	}
}
