#include "main.h"

/**
 * _printf_hexa - A function that prints an unsigned integer as a hexadecimal
 * number to the standard output.
 *
 * @nbr: The unsigned integer to be printed as a hexadecimal number.
 * @Xx: The format specifier to determine if the output should use lowercase
 * or uppercase letters for the hexadecimal digits.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 */
void _printf_hexa(unsigned int nbr, char Xx, int *len)
{
	unsigned int base_len;
	char *base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		_printf_char(base[nbr % base_len], len);
	else
	{
		_printf_hexa(nbr / base_len, Xx, len);
		_printf_hexa(nbr % base_len, Xx, len);
	}
}
