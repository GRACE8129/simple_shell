#include <stdio>
#include <string.h>

int main(void)

{
	char command[] = "i love coding";

	char *taken;
	char *delim = " ";

	token = strtok(command,delim);

	while (token != NULL)
	{
		write(STDOUT_FILENO, "token: ", 7);
		write(STDOUT_FILENO, token, strlen(token));
		write(STDOUT_FILENO, "\n", 1);

		token = strtok(NULL, delim);
	}
	return (0);
}
