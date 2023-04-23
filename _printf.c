#include "main.h"

/**
 * flags - A function that selects the appropriate function for the format
 * specifier passed to it, and passes the va_list to the appropriate function.
 *
 * @args: A va_list containing the list of arguments passed to _printf.
 * @s: The format specifier character.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 *
 * Return: 0 on success, -1 on error.
 */
int flags(va_list args, const char s, int *len)
{
	int ret = 0;

	switch (s)
	{
		case 'd':
		case 'i':
			_printf_decimal(va_arg(args, int), len);
			break;
		case 'u':
			_printf_unsigned_int(va_arg(args, unsigned int), len);
			break;
		case 'c':
			_printf_char((char) va_arg(args, int), len);
			break;
		case 's':
			_printf_string(va_arg(args, char *), len);
			break;
		case '%':
			_printf_char(s, len);
			break;
		case 'x':
		case 'X':
			_printf_hexa(va_arg(args, unsigned int), s, len);
			break;
		case 'p':
			_printf_adress(va_arg(args, void *), len);
			break;
		case 'o':
			_printf_octal(va_arg(args, unsigned int), len);
			break;
		case 'b':
			_printf_binary(va_arg(args, unsigned int), len);
			break;
		default:
			_printf_char(s, len);
			ret = -1;
			break;
	}
	return (ret);
}

/**
 * _printf - A function that prints a formatted string to the standard output.
 *
 * @format: The format string.
 *
 * Return: The number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
		if (flags(args, *format, &len) == -1)
			return (-1);
		}
		else
			_printf_char(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    return (0);
}