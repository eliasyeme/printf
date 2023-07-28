#include "main.h"

/**
 * base_len - length of an octal number
 * @num: input number
 * @base: input base
 *
 * Return: number length
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
		num = num / base;

	return (i);
}

/**
 * rev_string - reverses a string in place
 * @s: string to reverse
 *
 * Return: pointer to revered string
 */
char *rev_string(char *s)
{
	int len = 0, head;
	char tmp;
	char *dest;

	while (s[len])
		len++;

	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);

	_memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
 * write_base - write string to stdout
 * @str: String to parse
 */
void write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _memcpy - copy memory area
 * @dest: destination memeory
 * @src: source memeory
 * @n: The number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}


/**
 * hex_check - checks which hex function is calling it
 * @num: number to convert into letter
 * @x: tells which hex function is calling it
 *
 * Return: ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef", *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
