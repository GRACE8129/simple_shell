#include "shell.h"

/**
  * main - Entry point of the program
  *
  * Return: Always 0 (success)
  */

int main(void)
{
	char *message = "Hello, Betty! \n";
	ssize_t len = 13;

	if (write(1, message, len) != len)
		return (1);

	return (0);

}
