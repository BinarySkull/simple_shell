#include "main.h"
/**
 * _putchar - prints a character
 * Description: print a single character and send number of bytes written
 * @c: a signle char
 * Return: 1 on sucess
*/

int _putchar(char c)
{
	unsigned int i;

	i = write(1, &c, 1);
	return (i);
}

/**
 * _puts - prints a complete string
 * Description: it send every char to _putchar to print
 * @str: '*str' is a pointer pointing the first char in the string
 * Return: void
 */

void _puts(char *str)
{
	unsigned int counter_str;

	for (counter_str;str[counter_str] != 0; counter_str++)
		_putchar(str[counter_str]);
}
