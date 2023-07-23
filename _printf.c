#include "main.h"

/**
 * call_f - print to stdout
 * @c: format specifier
 * @args: argument list
 * Return: printer function or NULL on fail
 */
int call_f(char c, va_list args)
{

	int i;

	phandler_t fn[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_p},
		{'d', print_i},
		{'i', print_i},
		{'\0', NULL}
	};

	i = 0;
	while (fn[i].c)
	{
		if (c == fn[i].c)
			return (fn[i].f(args));
		i++;
	}
	return (-1);
}

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

			len += call_f(format[i], args);
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
