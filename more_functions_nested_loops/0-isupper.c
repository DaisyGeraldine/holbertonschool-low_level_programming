#include "main.h"
/**
 * _isupper - task 00
 * @c : variable to validate
 * Description:  function that checks for uppercase character
 * Return: always
 */
int _isupper(int c)
{
	char u = c;

	if (u >= 65 && u <= 90)
		return (1);
	else
		return (0);
}
