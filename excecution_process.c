#include "holberton.h"
#include <sys/stat.h>

/**
 * exc_process - Free memory.
 * @token_line: line splited into tokens
 * @token_path: path splited into tokens
 * Return: No return.
 */

void exc_process(char **token_line, char **token_path)
{
	int i = 0;
	pid_t process_exce;
	struct stat st;

	if (stat(token_line[0], &st) == 0)
	{
	process_exce = fork();
	wait(NULL);
		if (process_exce == 0)
		{
			execve(token_line[0], token_line, environ);
			write(1, "\n", 1);
			write(1, "\n", 1);
			write(1, "\n", 1);
			write(1, "\n", 1);
			exit(127);
		}

	}
	else
	{
	process_exce = fork();
	wait(NULL);
		if (process_exce == 0)
		{
			for (i = 0; token_path[i]; i++)
			{
				if (stat(token_path[i], &st) == 0)
				{
				execve(token_path[i], token_line, environ);
				}
			}
			write(1, "\n", 1);
			write(1, "\n", 1);
			write(1, "\n", 1);
			write(1, "\n", 1);
			exit(127);
		}
	}
}
