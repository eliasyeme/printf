#include "main.h"

/**
 * print_str - print string
 * @s: string
 * Return: number of char
 */
int print_str(char *s)
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
