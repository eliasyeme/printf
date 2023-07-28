#include "main.h"

/**
 * print_String - print non printable characters
 * @args: argument list
 *
 * Return: character length.
 */
int print_String(va_list args)
{
	int count, len = 0;
	char *res, *s = va_arg(args, char *);

	if (!s)
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if (isNonAlphaNumeric(*s))
		{
			count += _puts("\\x");
			res = convert(*s, 16, 0);
			if (!res[1])
				len += _putchar('0');
			len += _puts(res);
		}
		else
			len += _putchar(*s);
	}
	return (len);
}

/**
 * isNonAlphaNumeric - is a non-alphanumeric
 * @c: input char
 *
 * Return: 0 or 1
 */
int isNonAlphaNumeric(char c)
{
	return ((c > 0 && c < 32) || c >= 127);
}

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag to set hex to upper or lower
 *
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = NUL;
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);

	return (ptr);
}
