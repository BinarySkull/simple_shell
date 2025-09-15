#include "main.h"
/**
 * _putchar - prints a character
 * Description: print a single character and send a number of bytes written
 * @c: a single char
 * Return: 1 on sucess
*/

int _putchar(char c)
{
	unsigned int i;

	i = write(1, &c, 1);
	return (i);
}
