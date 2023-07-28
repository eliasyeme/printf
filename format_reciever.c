#include "main.h"

/**
 * format_handler - handle input string and format
 * @format: input string
 * @fn_list: funtion list to handle formats
 * @args: argument list
 *
 * Return: character length
 */
int format_handler(const char *format, handler_t fn_list[], va_list args)
{
	int i, j, r_val, len;

	len = 0;
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; fn_list[j].f != NULL; j++)
			{
				if (format[i + 1] == fn_list[j].f[0])
				{
					r_val = fn_list[j].fn(args);
					if (r_val == -1)
						return (-1);
					len += r_val;
					break;
				}
			}
			if (!fn_list[j].f && format[i + 1] != ' ')
			{
				if (format[i + 1])
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					len = len + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	return (len);
}
