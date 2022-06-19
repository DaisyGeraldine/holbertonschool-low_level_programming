#include "main.h"
/**
 * string_toupper - task 05
 * @s : Array
 * Description:function that changes all lowercase letters of a string to upper
 * Return: always
 */
char *string_toupper(char *s)
{
	int i = 0, len = 0;

	while (*(s + len))
		len++;

	for (; i < len; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
	return (s);
}
