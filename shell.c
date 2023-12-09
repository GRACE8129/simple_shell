#include "shell.h"

int main(void)
{
	char command[];

	while (true)
	{

		view_prompt();
		read_command(command, sizeof(command));
		execute_command(command);

	}

	return (0);
}
