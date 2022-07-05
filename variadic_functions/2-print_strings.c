#include <stdio.h>
#include <stdarg.h>
/**
 * print_strings - task 02
 * @separator : is the string to be printed between the strings
 * @n : is the number of integers passed to the function
 * Description: function that prints strings, followed by a new line
 * Return: always
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i = 0;
	const char *str;

	if (separator == NULL)
		separator = "";

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, const char*);
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);
		if (i != (n - 1))
			printf("%s", separator);
	}
	va_end(ap);
	printf("\n");
}
