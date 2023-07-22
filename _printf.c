#include "main.h"

/**
 * _printf - simple implementation of printf
 * @format: string to handle and print
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int i = 0, len = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			
			len += call_f(format[i])(args);
		}
		else
			len += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
