#include "main.h"

/**
 * check - check for specfier
 * @c: char to check
 * Return: 1 if true 0 if false
 */
int check(char c)
{
	if (c == 'c' || c == 's' || c == '%')
		return (1);

	return (0);
}
/**
 * _printf - simple implementation of printf
 * @format: string to handle and print
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int i, len = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (check(format[i]))
				len += call_f(format[i])(args);
		}
		else
			len += _putchar(format[i]);
	}
	va_end(args);
	return (len);
}
