#include "main.h"

/**
 * _printf - handle string with format specifier
 * @format: string with format specifier
 *
 * Return: character length
 */
int _printf(const char *format, ...)
{
	int len;
	handler_t fn_list[] = {
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"c", print_char},
		{"s", print_string},
		{"b", print_binary},
		{"u", print_unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_String},
		{"p", print_pointer},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL},
	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	len = format_handler(format, fn_list, args);
	va_end(args);
	return (len);
}

