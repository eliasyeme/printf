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
int count = 0;
va_list arg;
va_start(arg, format);

if (format == NULL)
{
va_end(arg);
return (-1);
}
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 's')
{
char *str = va_arg(arg, char*);
if (str == NULL)
{
_putchar('%');
_putchar('s');
count += 2;
}
else
{
while (*str != '\0')
{
_putchar(*str);
str++;
count++;
}
}
}
else if (*format == 'd')
{
int num = va_arg(arg, int);
if (num == 0)
{
_putchar('0');
count++;
}
else
{
char buffer[20];
int i = 0;
if (num < 0)
{
_putchar('-');
count++;
num = -num;
}
while (num > 0)
{
buffer[i] = (num % 10) + '0';
num /= 10;
i++;
}
while (i > 0)
{
i--;
_putchar(buffer[i]);
count++;
}
}
}
else
{
_putchar('%');
count++;
if (*format != '\0')
{
_putchar(*format);
count++;
}
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(arg);
return (count);
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
char s[10] = "hello";
int x = 20;

_printf("%s\n", s);
_printf("%d\n", x);
return (0);
}
