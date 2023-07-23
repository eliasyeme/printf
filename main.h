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
int _putchar(char c);
int print_s(va_list);
int print_c(va_list);
int print_p(va_list);
int print_i(va_list);

#endif /* MAIN_H */
