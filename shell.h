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


void view_prompt(void);
void circuitminds_print(const char *text);
void read_input(char *input, size_t size);
void execute_input(const char *input);
void execute_builtin(const char *input);
void execute_external(const char *input, char *arguments[]);

/* declaration for is_builtin function*/
bool is_builtin(const char *input);


#endif /*SHELL_H */
