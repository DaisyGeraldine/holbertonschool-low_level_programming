#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * _strpbrk - task 04
 * @s : string
 * @accept : string to validate
 * Description: function locates the first occurrence in the string s
 * of any of the bytes in the string accept.
 * Return:  a pointer to the byte in s that matches one of the bytes in accept.
 */
char *_strpbrk(char *s, char *accept)
{
	char *start = accept;

	while (*s)
	{
		while (*accept)
		{
			if (*accept == *s)
				return (s);
			accept++;
		}

		accept = start;
		s++;
	}
	return (NULL);
}
