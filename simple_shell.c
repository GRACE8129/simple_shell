#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

/*for buffer*/
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
#define MAX_NUM_ARGS 64

/* Declare the extern variable */
extern char **environ;

void view_prompt(void);
void jag_print(const char *text);
void read_input(char *input, size_t size);
void execute_input(const char *input);
void execute_builtin(const char *input, char **environ);
void execute_external(const char *input, char *arguments[]);

/* declaration for is_builtin function*/
bool is_builtin(const char *input);


#endif /*SHELL_H */
#include "shell.h"

/**
  * is_builtin - check if the given command is a built_in command.
  * @input: The command to be checked.
  *
  * Return: true if the command is built-in, false otherwise.
  */
bool is_builtin(const char *input)
{
	/*Compare the input command with the names of built-in commands*/
	if (strcmp(input, "exit") == 0 || strcmp(input, "env") == 0)
	{
		/* Return true if it's a built-in command*/
		return (true);
	}
	/* Return false if it's not a built-in command*/
	return (false);
}
#include "shell.h"

/**
 * execute_builtin - Execute built-in commands.
 * @input: The command to be executed.
 * @environ: The environment variable.
 */
void execute_builtin(const char *input, char **environ)
{
	if (strcmp(input, "exit") == 0)
	{
		jag_print("Exiting shell. \n");
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(input, "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			jag_print(*env);
			jag_print("\n");
			env++;
		}
	}
}
#include "shell.h"

/**
  * execute_input - executes a giving input command.
  *  @input: The command to be executed.
  */

void execute_input(const char *input)
{
	pid_t child_pid = fork();

	if (child_pid == -1)

	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execlp("/bin/sh", "sh", "-c", input, (char *)NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
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
			jag_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			jag_print("Error reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
#include "shell.h"

/**
  * jag_print - prints the given text to the standard output.
  * @text: the text to be printed.
  */

void jag_print(const char *text)

{
	write(STDOUT_FILENO, text, strlen(text));

}
#include "shell.h"

/**
 * main - execute the shell.
 *
 * Return: 0
 */

int main(void)
{
	char input[250];

	while (true)
	{

		view_prompt();
		read_input(input, sizeof(input));

		if (is_builtin(input))
		{
			execute_builtin(input, environ);
			continue;
		}
		execute_input(input);
	}

	return (0);
}
#include "shell.h"

/**
  * execute_external - Executes external commands.
  * @input: The command to be executed.
  * @arguments: The array of command and arguments.
  */

void execute_external(const char *input, char *arguments[])
{
	int arg_count = 0;

	char *token = strtok((char *)input, " ");

	while (token != NULL && arg_count < MAX_NUM_ARGS - 1)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	arguments[arg_count] = NULL;
}
#include "shell.h"

/**
  * view_prompt - displays the command prompt.
  *
  * Return: void
  */

void view_prompt(void)

{
	jag_print("circuit_shell$ ");
}
