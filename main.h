#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define NUL '\0'

/**
 * struct handler - format specfier and function
 * function to handle them
 * @f: format
 * @fn: function to call
 */
struct handler
{
	char *f;
	int (*fn)(va_list args);
};
typedef struct handler handler_t;


int _printf(const char *format, ...);
int _putchar(char c);
int format_handler(const char *format, handler_t f_list[], va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_binary(va_list args);
int print_unsigned_integer(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_String(va_list args);
int print_pointer(va_list args);
int print_rev(va_list args);
int print_rot13(va_list args);

int print_number(va_list args);
unsigned int base_len(unsigned int, int);
char *rev_string(char *str);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsigned_helper(unsigned int n);
int hex_check(int n, char x);
int print_hex_aux(unsigned long int num);
int isNonAlphaNumeric(char c);
int _puts(char *str);
char *convert(unsigned long int num, int base, int lowercase);
#endif
