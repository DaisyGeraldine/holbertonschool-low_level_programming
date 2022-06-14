#include "main.h"
/**
 * _isdigit - task 01
 * @c : variable to validate
 * Description:  function that checks for a digit (0 through 9)
 * Return: always
 */
int _isdigit(int c)
{
	char dig = c; /*Convert en character*/

	if (dig >= 48 && dig <= 57)
		return (1);
	else
		return (0);
}
