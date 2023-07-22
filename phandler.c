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

/**
 * print_i_helper - helper function to print_i
 * @n: number to print
 * Return: number of characters
 *
 */
int print_i_helper(int n)
{
unsigned int i;
int count = 0;

i = n;
if (n < 0)
{
_putchar('-');
count++;
i = -1;
}

if (i < 10)
{
count += _putchar(i + '0');
return (count);
}
if (i > 9)
{
count += print_i_helper(i / 10) + 1;
_putchar((i % 10) + '0');
return (count);
}
return (0);
}
/**
 * print_1 - print integer to stdout
 * @args: The argument pointer
 * Return: number of characters
 *
 *
 *
 */
int print_i(va_list args)
{
int i = va_arg(args, int);
int len = print_i_helper(i);
return (len);
}
