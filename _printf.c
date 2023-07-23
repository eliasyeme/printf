#include "main.h"

/**
 * _printf - simple implementation of printf
 * @format: string to handle and print
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	_vprintf(format, args);
	va_end(args);
	return (0);
}
