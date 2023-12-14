#include "shell.h"

/**
  * main - Print Hello, Betty!
  *
  * Return: 0
  */

int main(void)
{
	char *string = "Hello, Betty!";

	if (*string != '\0')
		puts(string);
	return (0);
}
