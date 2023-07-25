#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct phandler - print handler struct
 * @c: format specifier
 * @f: handler function
 */
struct phandler
{
	char c;
	int (*f)(va_list args);
};

/**
 * phandler_t - print handler type
 */
typedef struct phandler phandler_t;

int _printf(const char *format, ...);
int _vprintf(const char *format, va_list);
int _putchar(char c);
int print_s(char *);
int print_c(va_list);
int print_p(va_list);
int print_i(va_list);
int print_str(char *);
int print_num(int);
char *convert(unsigned long num, int base, int lower);
int print_binary(va_list);
int print_u(va_list u);
int print_o(va_list o);
int print_X(va_list X);
int print_x(va_list x);

#endif /* MAIN_H */
