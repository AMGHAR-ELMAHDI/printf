#include "main.h"

/**
 * _printf_decimal - A function that prints a decimal integer to the standard
 * output.
 *
 * @n: The integer to be printed.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 */
void _printf_decimal(int n, int *len)
{
	unsigned int number;

	number = n;

	if (n < 0)
	{
		_printf_char('-', len);
		number *= -1;
	}

	if (number < 10)
		_printf_char(number + '0', len);
	else
	{
		_printf_decimal(number / 10, len);
		_printf_decimal(number % 10, len);
	}
}
