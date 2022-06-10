#include "main.h"
/**
 * _isalpha - task 04
 * @c : Caracter to validate
 * Description: 'function that checks for lowercase or uppercase character'
 * Return: Always 1 when is true
 */
int _isalpha(int c)
{
	char i;
	int m = 0;

	i = c;
	if (i >= 65 && i <= 122)
	{
		if (i >= 91 && i <= 96)
			m = 0;
		else
			m = 1;
	}
	return (m);
}
