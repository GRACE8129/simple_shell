#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

void view_prompt(void);
void circuitminds_print(const char *text);
void read_input(char *input, size_t size);
void execute_input(const char *input);

#endif /*SHELL_H */
