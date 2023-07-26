#include "main.h"

/**
 * get_flag - turn flag on based on formater
 * @s: specifier
 * @f: flag
 * Return: 1 flag found else 0
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
/**
 *
 */
int (*get_print(char s))(va_list, flags_t *)
{
	phandler_t func_arr[] = {
		{'i', print_int},
		{'d', print_int},
		{'u', print_unsigned},
		{'s', print_string_handler},
		{'c', print_char},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'b', print_binary},
		{'o', print_octal},
		{'%', print_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}

/**
 * _vprintf - takes format string and prints it
 * @format: format string
 * @args: argsument list
 * Return: length of the characters
 */
int _vprintf(const char *format, va_list args)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	flags_t flags = {0, 0, 0};

	register int len = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				len += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			len += (pfunc)
				? pfunc(args, &flags)
				: _printf("%%%c", *p);
		} else
			len += _putchar(*p);
	}
	_putchar(-1);
	return (len);
}
