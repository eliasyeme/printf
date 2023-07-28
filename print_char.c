#include "main.h"

/**
 * print_char - prints character
 * @args: argument list
 *
 * Return: 1 always
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
