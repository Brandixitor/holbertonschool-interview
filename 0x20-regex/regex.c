#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "regex.h"

/**
 * regex_match - checks whether a given pattern
 * matches a given string
 * @str: String to compare
 * @pattern: Pattern to be compared
 * Return: 1 in match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
		int cheks1 = 0, checks2 = 0;

	if (!str || !pattern)
		return (0);

	cheks1 = *str && (*str == *pattern || *pattern == '.');
	checks2 = *(pattern + 1) == '*';

	if (!*str && !checks2)
		return (*pattern ? 0 : 1);

	if (cheks1 && checks2)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (cheks1 && !checks2)
		return (regex_match(str + 1, pattern + 1));
	else if (checks2)
		return (regex_match(str, pattern + 2));

	return (0);
}
