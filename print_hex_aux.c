#include "main.h"

/**
 * print_hex_aux - prints an hexgecimal number
 * @num: input number
 *
 * Return: number length
 */
int print_hex_aux(unsigned long int num)
{
	long i, len = 0;
	long *array;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		len++;
	}
	len++;
	array = malloc(len * sizeof(long int));

	for (i = 0; i < len; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (len);
}
