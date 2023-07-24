#include "main.h"

/**
 * _printf - print string to stdout
 * @format: format string
 * Return: number of chars
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list arg;

	if (format == NULL)
		return (-1);

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				count += print_str(va_arg(arg, char*));
			}
			else if (*format == 'd')
			{
				count += print_num(va_arg(arg, int));
			}
			else
			{
				count += _putchar('%');
				if (*format != '\0')
					count += _putchar(*format);
			}
		}
		else
			count += _putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
