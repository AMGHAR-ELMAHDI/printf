#include "main.h"

/**
 * _printf_octal - Prints an unsigned integer in octal notation
 *
 * @nbr: The integer to print
 * @len: A pointer to the length of the output
 */
void _printf_octal(unsigned int nbr, int *len)
{
	int *octal;
	int i, j;

	j = 0;
	octal = malloc(sizeof(int) * 32);
	if (nbr == 0)
	{
		_printf_char('0', len);
		free(octal);
		return;
	}
	while (nbr != 0)
	{
		octal[j] = nbr % 8;
		nbr /= 8;
		j++;
	}
	for (i = j - 1; i >= 0; i--)
	{
		_printf_char(octal[i] + '0', len);
	}
	free(octal);
}
