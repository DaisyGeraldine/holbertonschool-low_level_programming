#include "main.h"
#include <string.h>
/**
 * *_strchr - task 02
 * @s : string
 * @c : char to validate
 * Description: function that locates a character in a string.
 * Return: pointer to the first occurrence
 */
char *_strchr(char *s, char c)
{

	while (*s)
	{
		if (*s == c)
		{
			if (*s == '\0')
				return (s);
			return (s);
		}
		s++;
	}
	return (NULL);
}
