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
	int bits = sizeof(unsigned int) * 8;
	int i;


	for (i = bits - 1; i >= 0; i--)
	{
		if (num & (1 << i))
			break;
	}
	if (i < 0)
	{
		_printf_char('0', len);
		return;
	}
		for (; i >= 0; i--)
		_printf_char((num & (1 << i)) ? '1' : '0', len);
}
