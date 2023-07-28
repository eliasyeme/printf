#include "main.h"

/**
 * print_pointer - prints an hexgecimal number
 * @args: argument list
 *
 * Return: character length
 */
int print_pointer(va_list args)
{
	void *p;
	char *s = "(nil)";
	long a;
	int b, i;

	p = va_arg(args, void*);
	if (!p)
	{
		for (i = 0; s[i]; i++)
			_putchar(s[i]);

		return (i);
	}

	a = (unsigned long)p;
	_putchar('0');
	_putchar('x');
	b = print_hex_aux(a);
	return (b + 2);
}
