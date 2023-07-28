#include "main.h"

/**
 * _putchar - write character to stdout
 * @c: character to print
 *
 * Return: 1 on success -1 on fail
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - prints string to stdout
 * @str: string to print
 *
 * Return: chars length
 */
int _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}
