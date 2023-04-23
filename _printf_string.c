#include "main.h"

/**
 * _printf_string - A function that prints a string to the standard output.
 *
 * @s: The string to be printed.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 */
void _printf_string(char *s, int *len)
{
	char hex[2];
	int i;

	if (s == NULL)
	{
		_printf_string("(null)", len);
		return;
	}

	while (*s)
	{
		if (*s < 32 || *s >= 127)
		{
			_printf_char('\\', len);
			_printf_char('x', len);
			hex[0] = (*s >> 4) & 0xF;
			hex[1] = *s & 0xF;
			for (i = 0; i < 2; i++)
			{
				if (hex[i] < 10)
					_printf_char('0' + hex[i], len);
				else
					_printf_char('A' + (hex[i] - 10), len);
			}
		}
		else
			_printf_char(*s, len);
		s++;
	}
	_printf_char('\0', len);
}

