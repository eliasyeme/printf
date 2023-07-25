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

	if (*format == '\0')
		return (0);

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				count += print_str(va_arg(arg, char*));
			else if (*format == 'c')
				count += _putchar(va_arg(arg, int));
			else if (*format == 'd' || *format == 'i')
				count += print_i(arg);
			else if (*format == '%')
				count += _putchar('%');
			else if (*format == 'b')
				count += print_binary(arg);
			else if (*format == 'u')
				count += print_u(arg);
			else if (*format == 'o')
                                count += print_o(arg);
			else if (*format == 'X')
                                count += print_X(arg);
			else if (*format == 'x')
                                count += print_x(arg);
			else
				count += _putchar(*format);
		}
		else
			count += _putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
