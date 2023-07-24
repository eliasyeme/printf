#include "main.h"


/**
 * print_i - print integer to stdout
 * @args: The argument pointer
 * Return: number of characters
 */
int print_i(va_list args)
{
	int n = va_arg(args, int);
	int mod = 1, len = 0;
	unsigned int num;

	if (n < 0)
	{
		len += _putchar('-');
		num = -n;
	}
	else
		num = n;

	while (num / mod > 9)
		mod *= 10;

	while (mod > 0)
	{
		len += _putchar('0' + (num / mod));
		num %= mod;
		mod /= 10;
	}
	return (len);
}
