#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * _strtok - generates array of words from a string
 * @str: original string
 * @delimiters: delimiter characters
 *
 * Return: array of strings
 */
char *_strtok(char *str, char *delimiters)
{
	char *subString;
	int initialBufSize = 10, currentBufSize = 10;
	int counter = 0, subStringIndex = 0, firstString = 1, isDelimiter = 0;

	subString = malloc(initialBufSize);
	if (subString == NULL)
	{
		free(subString);
		return (NULL);
	}
	while (str[counter] != '\0')
	{
		printf("%c", str[counter]);
		if (check_is_delimiter(str[counter], delimiters) == 1)
		{
			subString[subStringIndex] = '\0';
			isDelimiter = 1;
			currentBufSize = initialBufSize;
			printf("%s\n", subString);
		} else
		{
			firstString = 0;
			subString[subStringIndex] = str[counter];
			subStringIndex++;
		}
		counter++;
	}

	return (subString);
}


/**
 * check_is_delimiter - check if char is delimiter
 * @c: character
 * @delimiters: string of delimiter characters
 *
 * Return: 1 if is delimiter 0 other wise
 */
int check_is_delimiter(char c, char *delimiters)
{
	int i = 0;

	while (delimiters[i] != '\0')
	{
		if (delimiters[i] == c)
			return (1);
	}

	return (0);
}
