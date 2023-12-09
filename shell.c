#include "shell.h"

int main(void)
{
	char input[250];

	while (true)
	{

		view_prompt();
		read_input(input, sizeof(input));
		execute_input(input);

	}

	return (0);
}
