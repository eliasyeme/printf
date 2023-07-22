#include "main.h"

/**
	* _putchar - print character to stdout
	* @c: character to be printed
	* Return: 1 always
	*/
int _putchar(char c)
{
	write(STDIN_FILENO, &c, 1);
	return (1);
}
