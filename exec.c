#include "shell.h"

/**
  * execute_input - executes a giving input command.
  *  @input: The command to be executed.
  */

void execute_input(const char *input)
{
	pid_t child_pid = fork();

	if (child_pid == -1)

	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execlp("/bin/sh", "sh", "-c", input, (char *)NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
