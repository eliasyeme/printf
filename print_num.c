#include "main.h"

/**
* print_num - print digits
* @num: input number
* Return: length of the number
*/
int print_num(int num)
{
	int count = 0;
	char buffer[20];
	int i = 0;

	if (num == 0)
		count += _putchar('0');
	else
	{
		if (num < 0)
		{
			count += _putchar('-');
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
			count += _putchar(buffer[i]);
		}
	}
	return (count);
}
