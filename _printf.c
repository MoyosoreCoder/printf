#include "main.h"

void print_buf(char buff[], int *buf_ind);

/**
 * _printf - function that prints formatted strings
 * @format: va list parameter
 *
 * Return: the number of count
 */
int _printf(const char *format, ...)
{
	int i; print = 0; printed_ch = 0;
	int flags, width, precision, size, buf_ind = 0;
	va_list options;
	char buffer(BUFF_SIZE);

	if (*format == NULL)
	{
		return (- 1);

		va_start(options, format);

		for (i = 0; format && format[i] != '\0'; i++)
			if (format[i] != '%')
			{
				buffer[buf_ind++] = format[i];
				if (buf_ind == BUFF_SIZE)
					print_buffer(buffer, &buf_ind);
				printed_ch++;
			}
			else
			{
				print_buffer(buffer,  &buf_ind);
				flags = get_flags(format, &i);
				width = get_width(format, &i, options);
				precision = get_precision(format, &i, options);
				size = get_size(format, &i);
				++i;
				print = handle_printing(format, &i, options, buffer, flags, width, precision, size);
				if (print == -1)
					return (-1);
				print_ch += print;
			}
	}
	print_buffer(buffer, &buf_ind);

	va_end(options);

	return (print_ch);
}
/**
 * print_buffer - prints the contenets of the buffer if it exist
 * @buf_ind: index at whichto add next char
 * @buffer: array of characters
 */
void print_buffer(char buffer[], int *buf_ind)
{
	if (*buf_ind > 0)
		write (1, &buffer[0], *buf_ind);
	*buf_ind = 0;
}

