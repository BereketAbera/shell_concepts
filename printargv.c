#include <stdio.h>
#include "holberton.h"

/**
 * printargv - print argv withoug argc
 * @argv: arguments array of strings
 *
 * Return: nothing
 */
void printargv(char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
}
