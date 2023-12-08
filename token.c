#include <stdio>
#include <string.h>

int main()

{
	char command[] = "i love coding";

	char *taken;
	char *delim = " ";

	token = strtok(command,delim);

	while (token != NULL)
	{
		printf("token: %s\n", token);

		token = strtok(NULL, delim);
	}
	return (0);
}
