#include "main.h"

/**
 * print_unsigned_integer - prints Unsigned integers
 * @args: argument list
 *
 * Return: number length
 */
int print_unsigned_integer(va_list args)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (print_unsigned_helper(num));

	if (num < 1)
		return (-1);
	return (print_unsigned_helper(num));
}

/**
 * print_unsigned_helper - prints an unsigned number
 * @n: unsigned integer to be printed
 *
 * Return: number length
 */
int print_unsigned_helper(unsigned int n)
{
	int mod, len;
	unsigned int num;

	mod = 1;
	len = 0;

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
