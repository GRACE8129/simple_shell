#include <stdio.h>
#include <string.h>

int main(void)

{
	char input[] = "i love coding";

	char *token;
	char *delim = " ";

	token = strtok(input, delim);

	while (token != NULL)
	{
		write(STDOUT_FILENO, "token: ", 7);
		write(STDOUT_FILENO, token, strlen(token));
		write(STDOUT_FILENO, "\n", 1);

		token = strtok(NULL, delim);
	}
	return (0);
}
