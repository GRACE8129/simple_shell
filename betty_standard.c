#include "shell.h"

/**
  * main - Print Hello, Betty!
  *
  * Return: 0
  */

int main(void)
{
	char *string = "Hello, Betty!\n";
	ssize_t len = strlen(string);


	if ((write(1, string, len)) != len)
		return (1);

	return (0);
}
