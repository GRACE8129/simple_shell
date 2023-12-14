#include "shell.h"

/**
 * execute_input - executes a given input command.
 * @input: The command to be executed.
 */
void execute_input(const char *input)
{
	pid_t child_pid;
	int status;

	/* Fork a child process */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* Child process */
		/* Tokenize the input command */
		char *arguments[MAX_NUM_ARGS];

		execute_external(input, arguments);
		/* Attempt to execute the command */
		execvp(arguments[0], arguments);
		/* If execvp fails, print an error message */
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		/* Wait for the child to complete */
		waitpid(child_pid, &status, 0);
		/* Check if the child process exited normally */
		if (WIFEXITED(status))
		{
			/* Print the exit status if needed */
			/* printf("Child exited with status %d\n", WEXITSTATUS(status)); */
		}
		else if (WIFSIGNALED(status))
		{
			/* Print information about the signal that caused the child to terminate */
			/* printf("Child process terminated by signal %d\n", WTERMSIG(status)); */
		}
	}
}
