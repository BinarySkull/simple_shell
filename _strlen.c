#include "main.h"

/**
 * _strlen - calulate the length of string
 * Description: it calulate the string passed to _puts
 * @s: '*s' is a pointer
 * Return: length of string
 */
int _strlen(char* str)
{
	int i;

	for (i = 0; str[i] != '\0';)
	{
		i++;
	}

	return i;
}