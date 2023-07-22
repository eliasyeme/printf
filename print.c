#include "main.h"

/**
 * call_f - print to stdout
 * @c: format specifier
 * Return: printer function or NULL on fail
 */
int (*call_f(char c))(va_list)
{
	int i;

	phandler_t fn[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_p},
		{'d', print_i},
		{'i', print_i},
		{'\0', NULL}
	};

	i = 0;
	while (fn[i].c)
	{
		if (c == fn[i].c)
			return (fn[i].f);
		i++;
	}
	return (NULL);
}
