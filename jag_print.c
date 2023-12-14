#include "shell.h"

/**
  * jag_print - prints the given text to the standard output.
  * @text: the text to be printed.
  */

void jag_print(const char *text)

{
	write(STDOUT_FILENO, text, strlen(text));

}
