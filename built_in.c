#include "shell.h"

/**
 * execute_builtin - Execute built-in commands.
 * @input: The command to be executed.
 * @environ: The environment variable.
 */
void execute_builtin(const char *input, char **environ)
{
	if (strcmp(input, "exit") == 0)
	{
		jag_print("Exiting shell. \n");
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(input, "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			jag_print(*env);
			jag_print("\n");
			env++;
		}
	}
}
