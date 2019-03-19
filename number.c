#include "holberton.h"

/**
 * print_number - using only _putchar
 * @n: the integer to print
 * @is_unsigned: flag if unsigned
 *
 * Return: bytes printed
 */
int print_number(long n, int is_unsigned)
{
	int p, c = 0;
	unsigned long i = 10000000000000000000UL;

	if (!is_unsigned && n < 0)
	{
		c += _putchar('-');
		n = -n;
	}
	for (p = 0; i > 0; i /= 10)
	{
		unsigned int d = (n / i) % 10;

		if (d || p || i == 1)
		{
			c += _putchar(d + '0');
			p++;
		}

	}
	return (c);
}

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @l: lowercase or not
 * Return: string
 */
char *convert(unsigned long int num, int base, short l)
{
	static char *array;
	static char buffer[50];
	char *ptr;

	array = l ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	return (print_number(l, 1));
}



/**
 * print_address - prints address
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *prefix = "0x";
	int c;
	(void)params;
/* params->plus_flag ? "+0x" : "0x"; */

	if (!n)
		return (_puts("(nil)"));
	prefix = str_concat(prefix, convert(n, 16, 1));
	c = _puts(prefix);
	free(prefix);
	return (c);
}
