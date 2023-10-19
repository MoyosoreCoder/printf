#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int print_str(va_list options);
int print_char(va_list options);
int print_percent(void);
int _putchar(char c);
int process_specifiers(const char *format, va_list options);

#endif
