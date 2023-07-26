#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/**
 * struct flags - flags to set for
 * @plus: flag for '+' char
 * @space: flag for ' ' char
 * @hash: flag for '#' char
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct phandler - print handler struct
 * @c: format specifier
 * @f: handler function
 */
struct phandler
{
	char c;
	int (*f)(va_list args, flags_t *f);
};

/**
 * phandler_t - print handler type
 */
typedef struct phandler phandler_t;

int _printf(const char *format, ...);
int _vprintf(const char *format, va_list);

/* alpha */
int _putchar(char c);
int print_string(char *);
int print_string_handler(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);
int print_percent(va_list l, flags_t *f);

/* numbers */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* base */
int print_hex_lower(va_list l, flags_t *f);
int print_hex_upper(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* util */
char *convert(unsigned long num, int base, int lower);

#endif /* MAIN_H */
