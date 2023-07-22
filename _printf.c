#include "main.h"

/**
 * _printf - simple implementation of printf
 * @format: string to handle and print
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int hlen;
	int len = 0;
	va_list args;

	phandler_t fn[] = {
		{'c', print_c},
		{'s', print_s},
		{'\0', NULL}
	};
	hlen = 3;

	if (format == NULL)
		return (-1);

	if (format[0] == '\0')
		return (0);

	va_start(args, format);
	len = print(args, format, hlen, fn);
	va_end(args);
	return (len);
}
