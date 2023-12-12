#include "shell.h"
#include <unistd.h>


/**
  * execute_builtin - Execute built-in commands.
  * @input: The command to be executed.
  */

void execute_builtin(const char *input)
{
	if (strcmp(input, "exit") == 0)
	{
		circuitminds_print("Exiting shell. \n");
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(input, "env") == 0)
	{
		extern char **environ;

		char **env = environ;
		while (*env != NULL)
		{
			circuitminds_print(*env);
			circuitminds_print("\n");
			env++;
		}
	}
}
