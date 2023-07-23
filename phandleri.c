#include "main.h"

/**
 * print_i_helper - helper function to print_i
 * @n: number to print
 * Return: number of characters
 *
 */
void print_i_helper(int n)
{
	unsigned int i;

	if (n < 0)
	{
		_putchar('-');
		i = -n;
	}
	else
		i = n;

	if (i / 10)
		print_i_helper(i / 10);
	_putchar((i % 10) + '0');
}

/**
 * print_i - print integer to stdout
 * @args: The argument pointer
 * Return: number of characters
 */
int print_i(va_list args)
{
	int i = va_arg(args, int);
	int n = i, len;

	if (i < 0)
		n = i * -1;

	while (n > 0)
	{
		n /= 10;
		len++;
	}

	print_i_helper(i);

	return (len);
}
