#include "shell.h"

/**
  * is_builtin - check if the given command is a built_in command.
  * @input: The command to be checked.
  *
  * Return: true if the command is built-in, false otherwise.
  */
bool is_builtin(const char *input)
{
	/*Compare the input command with the names of built-in commands*/
	if (strcmp(input, "exit") == 0 || strcmp(input, "env") == 0)
	{
		/* Return true if it's a built-in command*/
		return (true);
	}
	/* Return false if it's not a built-in command*/
	return (false);
}
