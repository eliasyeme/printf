#include "main.h"

/**
 * _printf - simple implementation of printf
 * @format: string to handle and print
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int i, j, hlen;
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
	for (i = 0; format[i]; i++)
	{
		char c0 = format[i];
		char c1 = format[i + 1];
		if(c0 == '%' && c1 != '%' && c1)
		{
			j = 0;
			while (j < hlen && (c1 != fn[j].c))
				j++;

			if (j < (hlen - 1))
			{
				len += fn[j].f(args);
				i++;
			}
			else
				len += _putchar(c0);
		}
		else
		{
			len += _putchar(c0);
			if (c0 == '%' && c1 == '%')
				i++;
		}
	}
	va_end(args);

	return (len);
}
