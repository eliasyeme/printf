#include <stdarg.h>
#include <unistd.h>
/**
 * _putchar - my function
 * @c: my variable
 * Return: zero
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * _printf - my next function
 * @format: my next variable
 * Return: zero
 */
int _printf(const char *format, ...)
{
int chars_printed = 0;
va_list args;
va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
	case 'c':{
		char ch = va_arg(args, int);

		chars_printed += _putchar(ch);
		break;
		}
	case 's':{
		char *str = va_arg(args, char *);

		while (*str)
		{
		chars_printed += _putchar(*str);
		str++;
		}
		break;
		}
	case '%':
		chars_printed += _putchar('%');
		break;
	default:
		break;
}
}
else
{
chars_printed += _putchar(*format);
}
format++;
}
va_end(args);
return (chars_printed);
}
/**
 * main - my main function
 *
 *
 * Return: zero
 *
 */
int main(void)
{
char ch = 'A';
char *str = "Hello, World!";


int chars_printed = _printf("Character: %c\n", ch);
chars_printed += _printf("String: %s\n", str);
chars_printed += _printf("Percentage sign: %%\n");

_printf("Total characters printed: %d\n", chars_printed);
return (0);
}
