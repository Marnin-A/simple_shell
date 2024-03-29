#ifndef E_SHELL_H
#define E_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/* Get environment */
extern char **environ;

/* to explain input size to max */
#define MAX_INPUT_SIZE 256


/* The needed fxn prototypes of helper fxn */

/* fxn prototype, print fxn */
void eprint(const char *string);

/* The fxn prototype, prompt display fxn */
void prompt_fxn(void);

/* fxn prototype, prompt exec. fxn */
void execute_pt(const char *uput);

char **tok_input(const char *uput, int *argc);

char *_strtok(char *str, const char *delim);

int num_digits(int num);

int _putchar(char c);

char *_getline(void);

char *set_path(char *cd_path, char *exec);

void execute_and_free(char *cd_path, char **ux_commandz1, char *exec);

#endif /* E_SHELL_H */
