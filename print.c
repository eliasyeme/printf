#include "main.h"

/**
 * print - print to stdout
 * @args: argument list
 * @format: string
 * @hlen: funtion list number
 * @fn: funtion list with specifier
 * Return: character length
 */
int print(va_list args, const char *format, int hlen, phandler_t fn[])
{

	int i, j;
	int len = 0;

	for (i = 0; format[i]; i++)
	{
		char c0 = format[i], c1 = format[i + 1];

		if (c0 == '%' && c1 != '%' && c1)
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

	return (len);
}
