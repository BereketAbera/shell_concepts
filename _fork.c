#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid;
	int status, count = 0;
	char * const argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (count < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
    			{
        			perror("Error:");
				exit(2);
 			}
		} else {
			wait(&status);
			if (WIFEXITED(status)){
				printf("Child exited succesfully\n");
			}
		}
		count++;
	}
	return (0);
}
