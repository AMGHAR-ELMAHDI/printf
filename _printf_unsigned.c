#include "main.h"

/**
 * _printf_unsigned_int - A function that prints an unsigned integer to the
 * standard output.
 *
 * @n: The unsigned integer to be printed.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 */
void _printf_unsigned_int(unsigned int n, int *len)
{
	if (n < 10)
		_printf_char(n + '0', len);
	else
	{
		_printf_decimal(n / 10, len);
		_printf_decimal(n % 10, len);
	}
}
