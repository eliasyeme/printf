#include "main.h"

/**
 * print_str - print string
 * @s: string
 * Return: number of char
 */
int print_string(char *s)
{
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		len++;
	}

	return (len);
}

/**
 * _putchar - print character to stdout
 * @c: input char
 * Return: 1 or error code
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - print char
 * @args: argument list
 * @f: flags
 * Return: always 1
 */
int print_char(va_list l, flags_t *f)
{
	UNUSED(f);
	_putchar(va_arg(l, int));
	return (1);
}

/**
 * print_string - handle s specifier
 * @args: argument list
 * @f: flags
 * Return: char len
 */
int print_string_handler(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	UNUSED(f);
	return (print_string(s));
}

/**
 * print_percent - prints percent character
 * @args: argument list
 * @f: flags
 * Return: 1 always
 */
int print_percent(va_list l, flags_t *f)
{
	UNUSED(l);
	UNUSED(f);
	return (_putchar('%'));
}
