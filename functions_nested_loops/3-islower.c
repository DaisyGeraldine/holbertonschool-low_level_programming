#include "main.h"
/**
 * _islower - task 03
 * @c : Caracter to validate
 * Description: 'function that checks for lowercase character'
 * Return: Always 0 (Success)
 */
int _islower(int c)
{
	char i;
	int m = 0;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (i == c)
			m = 1;
	}
	return (m);
}
