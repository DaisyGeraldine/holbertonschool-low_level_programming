#include <stdio.h>
#include <stdarg.h>
/**
 * print_numbers - task 00
 * @separator : is the string to be printed between numbers
 * @n : is the number of integers passed to the function
 * Description: function that prints numbers, followed by a new line
 * Return: always
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i = 0;

	if (separator == NULL)
		separator = "";

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (i != (n - 1))
			printf("%s", separator);
	}
	va_end(ap);
	printf("\n");
}
