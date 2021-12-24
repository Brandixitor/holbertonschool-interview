#include "holberton.h"

/**
 * main - program that multiplies two positive numbers
 * @argc: number of arguments
 * @argv: given arguments
 * Return: returns 0 if everything is fine otherwise 98 with an error
 **/
int main(int argc, char **argv)
{
	int i, y, len, len2, zero;

	if (argc != 3)
		_print_error();

	len = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	for (y = 1; y <= 2; y++)
	{
		i = 0;
		zero = 0;
		while (argv[y][i] != '\0')
		{
			if ((_isDigit(argv[y][i]) == 0) ||
					(_isDigit(argv[y][i]) == 2 && i != 0) ||
					(_isDigit(argv[y][i]) == 2 && _strlen(argv[y]) == 1))
				_print_error();
			if (argv[y][i] != '0')
				zero++;
			i++;
		}
		if (zero == 0)
		{
			_putchar('0');
			_putchar('\n');
			return (0);
		}
	}

	_mul(argv[1], argv[2], len, len2);
	return (0);
}
/**
 * _strlen - Calculates the length of a string
 * @str: String to calculate
 * Return: length of a string
 **/
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
/**
 * _mul - Multiply two numbers and return the res as a string
 * @nb: first number
 * @nb2: second number
 * @nblength: length of first number
 * @nb2length: length of second number
 **/
void _mul(char *nb, char *nb2, int nblength, int nb2length)
{
	int *res = NULL;
	int a = 0, b = 0;
	int counter = 0, counter2 = 0;
	int _nb = 0, _nb2 = 0, sum = 0, next = 0, i = 0;

	res = malloc(sizeof(int) * (nblength + nb2length + 1));

	for (a = nblength - 1, b = nb2length - 1, counter = 0, counter2 = 0;
			a >= 0; counter++, a--, counter2 = 0)
	{
		_nb = nb[a] - '0';

		for (b = nb2length - 1, next = 0; b >= 0; b--, counter2++)
		{
			_nb2 = nb2[b] - '0';

			sum = _nb * _nb2 + next + res[counter + counter2];
			next = sum / 10;

			res[counter + counter2] = sum % 10;
		}

		if (next > 0)
			res[counter + counter2] += next;
	}

	i = nblength + nb2length + 1;

	while (res[i] == 0)
		i--;

	for (; i >= 0; i--)
		_putchar(res[i] + '0');
	_putchar('\n');
}
/**
 * _isDigit - Checks if the character is a digit.
 * @c: Character to check
 * Return: 1 if the character is a digit otherwise 0
 **/
int _isDigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c == 45)
		return (2);
	return (0);
}
/**
 * _print_error - Prints a default error message when an error occurs.
 **/
void _print_error(void)
{
	int i = 0;
	char *msg = "Error";

	while (msg[i] != '\0')
	{
		_putchar(msg[i]);
		i++;
	}

	_putchar('\n');
	exit(98);
}
