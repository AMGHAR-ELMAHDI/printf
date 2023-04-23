#include "main.h"

/**
 * _printf_binary - Prints the binary representation of an unsigned integer
 *
 * @num: The unsigned integer to print in binary
 * @len: Pointer to integer to store the length of the printed string
 *
 * Return: void
 */
void _printf_binary(unsigned int num, int *len)
{
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

	while (mask > 0)
	{
		_printf_char((num & mask) ? '1' : '0', len);
		mask >>= 1;
	}
}
