#include "main.h"

/**
	* _putchar - print character to stdout
	* @c: character to be printed
	* Return: 1 on success -1 on fail
	*/
int _putchar(char c)
{
return(write(STDIN_FILENO, &c, 1));
}
