#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * _which - find command in PATH
 * @command: a command string
 *
 * Return: the directory of a command
 */
char *_which(char *command)
{
	char *paths;
	char *path;
	int index = 0, index2 = 0, commandIndex;
	struct stat st;

	paths = getenv("PATH");
	path = malloc(100);
	if (path == NULL)
	{
		free(path);
		return (NULL);
	}

	while (1)
	{
		if (paths[index] == ':' || paths[index] == '\0')
		{
			path[index2] = '/';
			index2++;
			commandIndex = 0;
			while (command[commandIndex] != '\0')
			{
				path[index2 + commandIndex] = command[commandIndex];
				commandIndex++;
			}
			path[index2 + commandIndex] = '\0';
			if (stat(path, &st) == 0){
				return (path);
			}
			index2 = 0;
			index++;
			if (paths[index] == '\0')
				break;
			continue;
		} else {
			path[index2] = paths[index];
			index++;
			index2++;
		}
	}

	return (NULL);
}

/**
 * main - entry point
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *path;

	path = _which(argv[1]);
	printf("%s\n", path);

	return (0);
}
