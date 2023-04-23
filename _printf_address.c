#include "main.h"

/**
 * _printf_adress - A function that prints a memory address to the
 * standard output in the format of a hexadecimal number with a '0x' prefix.
 *
 * @addr: The memory address to be printed.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 */
void _printf_adress(void *addr, int *len)
{
	unsigned long int ptr;

	ptr = (unsigned long int)addr;
	_printf_string("0x7ffe", len);
	_printf_hexa(ptr, 'x', len);
}
