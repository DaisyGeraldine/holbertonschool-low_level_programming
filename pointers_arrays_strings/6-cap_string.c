#include "main.h"
/**
 * cap_string - task 06
 * @s : Array
 * Description: function that capitalizes all words of a string
 * Return: always
 */
char *cap_string(char *s)
{
	int i = 0, len = 0;

	while (*(s + len))
		len++;

	for (; i < len; i++)
	{
		if (i == 0)
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i] - 32;
		if (s[i - 1] == ' ' || s[i - 1] == '\n' ||
		    s[i - 1] == '\t' || s[i - 1] == ',' ||
		    s[i - 1] == ';' || s[i - 1] == '.' ||
		    s[i - 1] == '!' || s[i - 1] == '?' ||
		    s[i - 1] == '"' || s[i - 1] == '(' ||
		    s[i - 1] == ')' || s[i - 1] == '{' ||
		    s[i - 1] == '}')
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i] - 32;
		}
	}
	return (s);
}
