#include "shell.h"

/**
  * circuitminds_print - prints the given text to the standard output.
  * @text: the text to be printed.
  */

void circuitminds_print(const char *text)

{
	write(STDOUT_FILENO, text, strlen(text));

}
