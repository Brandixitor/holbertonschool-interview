#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares two strings and returns 1 if the strings can be
 * considered identical, otherwise return 0.
 * @s1: string to compare
 * @s2: string to compare that can have wildcards
 * Return: 1 if strings are identical, else 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
