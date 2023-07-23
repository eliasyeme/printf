#include "main.h"

int _vprintf(const char *format, va_list args)
{
	int len = 0, state = 0;

	while (*format)
	{
		if (state == 0) {
			if (*format == '%')
			{
				state = 1;
			}
			else
				len += _putchar(*format);
		}
		else if (state == 1)
		{
			switch (*format)
			{
				case 'c':
					len += _putchar(va_arg(args, int));
					break;
				case 's':
					len += print_s(va_arg(args, char *));
					break;
				case '%':
					len += _putchar('%');
					break;
				default:
					len += _putchar(*format);
					break;
			}
			state = 0;
		}
		format++;
	}

	return (len);
}
