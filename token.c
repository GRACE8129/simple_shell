#include "shell.h"

/**
  * execute_external - Executes external commands.
  * @input: The command to be executed.
  * @arguments: The array of command and arguments.
  */

void execute_external(const char *input, char *arguments[])
{
	int arg_count = 0;

	char *token = strtok((char *)input, " ");

	while (token != NULL && arg_count < MAX_NUM_ARGS - 1)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	arguments[arg_count] = NULL;
}
