#include "main.h"
/**
 * convert - numbers to string
 * @num: input number
 * @base: base of the input
 * @lower: flag to set hex value in lower or upper
 * Return: pointer to string
 */
char *convert(unsigned long num, int base, int lower)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lower)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}

/**
 * print_binary - print in binary
 * @args: argument list
 * Return: number of char
 */
int print_binary(va_list args, flags_t *f)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 2, 0);

	UNUSED(f);
	return (print_string(str));
}

/**
 * print_hex_lower - prints hex in lower
 * @args: list of arguments
 * @f: set flag struct
 * Return: char len
 */
int print_hex_lower(va_list args, flags_t *f)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 16, 1);
	int len = 0;

	if (f->hash == 1 && str[0] != '0')
		len += print_string("0x");
	len += print_string(str);
	return (len);
}

/**
 * print_hex_upper - print hex upper
 * @args: list of arguments
 * @f: set flag struct
 * Return: char len
 */
int print_hex_upper(va_list args, flags_t *f)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 16, 0);
	int len = 0;

	if (f->hash == 1 && str[0] != '0')
		len += print_string("0X");
	len += print_string(str);
	return (len);
}

/**
 * print_o - print base 8 numbers
 * @args: list of arguments
 * @f: set flag struct
 * Return: char len
 */
int print_octal(va_list args, flags_t *f)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 8, 0);
	int len = 0;

	if (f->hash == 1 && str[0] != '0')
		len += _putchar('0');
	len += print_string(str);
	return (len);
}
