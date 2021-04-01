#include <stdio.h>
#include "holberton.h"

/**
 * main - run exercise questions
 * @argc: argument counter
 * @argv: argument values
 * 
 * Return: always 0
 */
int main (int argc, char **argv)
{
	char *line;

	// printf("Number of arguments: %d\n", argc);
	// printargv(argv);


	line = _getline(argv[0]);

	_strtok(line, " ");

	return (1);
}
