#include "main.h"

/**
 * print_s - print string
 * @args: argument list
 * Return: number of characters
 */
int print_s(va_list args)
{
	int i;
	char *s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i]; i++)
		_putchar(s[i]);

	return (i);
}

/**
 * print_c - print character
 * @args: argument list
 * Return: 1 from _putchar
 */
int print_c(va_list args)
{
	return (_putchar(va_arg(args, int)));
}
