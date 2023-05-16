#include "monty.h"


/**
 * string_is_int - checks if string is an int
 * @s: String to check
 * Return: 0 if is an int, any positive value if s exist
 * and is not an int, or -1 if s is NULL
 */

int string_is_int(char *s)
{
	int ret = 0, i = 0;

	if (!s)
		return (-1);
	if (s[i] == 45 || (s[i] >= 48 && s[i] <= 57))
		i++;
	else
		ret++;
	for (i = 1; s[i]; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
			continue;
		else
			ret++;
	}
	return (ret);
}
