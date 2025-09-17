#include "main.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The string to convert.
 *
 * Return: The converted integer, or 0 if no number is found.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int num = 0;

	if (s == NULL)
		return (0);

	/* Handle optional sign */
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}

	/* Convert digits */
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}

	return (num * sign);
}
