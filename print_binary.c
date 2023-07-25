#include "main.h"
/**
 * convert - numbers to string
 * @num: input number
 * @base: base of the input
 * @lower: flag to set hex value in lower or upper
 * Return: pointer to string
 *
 *
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
 *
 */
int print_binary(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
char *str = convert(num, 2, 0);

return (print_str(str));
}
