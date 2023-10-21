#include "main.h"

/**
 * print_intg - a function that prints format %d and %i
 * @options: va_list parameter
 *
 * Return: the number of count
 */
int print_intg(va_list options)
{
	char digits[10];

	int i = 0;

	int ch_count = 0;
	int num;

	num = va_arg(options, int);

	if (num < 0)
	{
		_putchar('-');
		ch_count++;
		num = -num;
	}
	if (num == 0)
	{
		ch_count += _putchar('0');
	}
	else
	{
		while (num > 0)
		{
			digits[i] = '0' + (num % 10);
			num /= 10;
			i++;
		}
		while (i > 0)
		{
			ch_count += _putchar(digits[i - 1]);
				i--;
		}
	}

	return (ch_count);
}
