#include "main.h"

/**
 * print_integer - prints an integer
 * @args: argument list
 *
 * Return: character length
 */
int print_integer(va_list args)
{
	int len;

	len = print_number(args);
	return (len);
}

/**
 * print_number - prints number
 * @args: argument list
 *
 * Return: number length
 */
int print_number(va_list args)
{
	int n, mod, len;
	unsigned int num;

	n  = va_arg(args, int);
	mod = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / mod > 9; )
		mod *= 10;

	for (; mod != 0; )
	{
		len += _putchar('0' + num / mod);
		num %= mod;
		mod /= 10;
	}

	return (len);
}
