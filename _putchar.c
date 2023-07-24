#include "main.h"

/**
 * _putchar - print character to stdout
 * @c: input char
 * Return: 1 or error code
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
