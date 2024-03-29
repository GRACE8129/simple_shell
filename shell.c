#include "shell.h"

/**
 * main - execute the shell.
 *
 * Return: 0
 */

int main(void)
{
	char input[250];

	while (true)
	{

		view_prompt();
		read_input(input, sizeof(input));

		if (is_builtin(input))
		{
			execute_builtin(input, environ);
			continue;
		}
		execute_input(input);
	}

	return (0);
}
