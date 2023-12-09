 #include "shell.h"
/**
  * read_input - Reads user input from stdin.
  * @input: The buffer to store user input.
  * @size: the size of the buffer.
  */

void read_input(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			circuitminds_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			circuitminds_print("Error reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
