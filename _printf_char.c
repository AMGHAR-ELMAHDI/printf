#include "main.h"

/**
 * _printf_char - A function that prints a character to the standard output.
 *
 * @c: The character to be printed.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 */
void _printf_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
