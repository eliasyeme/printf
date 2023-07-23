#include "main.h"

/**
 * print_s - print string
 * @s: string to print
 * Return: number of characters
 */
int print_s(char *s)
{
	int i;

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
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_p - print percent sign
 * @args: argument list
 * Return: 1 always
 */
int print_p(va_list args)
{
	(void) args;
	_putchar('%');
	return (1);
}
