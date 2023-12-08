#include "shell.h"

void circuitminds_print(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));

}
