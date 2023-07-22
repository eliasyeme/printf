#include "main.h"
#include <stdio.h>

/**
 * _printf - simple implementation of printf
 * @format: string to handle and print
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;

	va_start(args, format);
	len = vprintf(format, args);
	va_end(args);

	return (len);
}
