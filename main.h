#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* FLAGGING*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* THE SIZES*/
#define S_LONG 2
#define S_SHORT 1

/**
 *
 *
 */
struct fmt
{
	char fmt;
	int (*fm)(va_list, char [], int, int, int, int);
};
/**
 *
 *
 */
typdef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_printing(const char *fmt, int *i,
va_list options, char buffer[], int flags, int width, int precision, int size);

/* FUNCTIONS*/

#endif
