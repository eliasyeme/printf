#include "main.h"

/**
 * _printf - print string to stdout
 * @format: format string
 * Return: number of chars
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list arg;

	if (format == NULL)
		return (-1);

	if (*format == '\0')
		return (0);

	va_start(arg, format);
	len += _vprintf(format, arg);
	va_end(arg);
	return (len);
}
