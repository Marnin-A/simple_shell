#include "shell.h"

/**
 * execute_pt - Fxn to execute a prompt.
 * @uput: Ptr to a char. string input by the user.
 * Return: to void
 */
void execute_pt(const char *uput)
{
	pid_t child_pid;
	char **ux_commandz1, *exec, *cd_path;
	int w = 0, arCd = 0;
	char *token;

	child_pid = fork();

	if (child_pid == -1)
	{
	perror("fork was unsuccessful");
	exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
	ux_commandz1 = malloc(128 * sizeof(char *));
	if (ux_commandz1 == NULL)
	{
	perror("memory allocation was unsuccessful");
	exit(EXIT_FAILURE);
	}

		token = _strtok((char *)uput, " ");
		while (token != NULL)
		{
			ux_commandz1[w] = token;
			token = _strtok(NULL, " ");
			w++;
		}
		ux_commandz1[w] = NULL;

	exec = ux_commandz1[0];
	cd_path = "/bin/";
	cd_path = set_path(cd_path, exec);
	execute_and_free(cd_path, ux_commandz1, exec);
	}
	else
	{
	waitpid(child_pid, &arCd, 0);
	}
}
char *set_path(char *cd_path, char *exec)
{
	char *path;

	path = cd_path;
	path = malloc(strlen(path) + strlen(exec) + 1);
	if (path == NULL)
	{
	perror("memory allocation was unsuccessful");
	exit(EXIT_FAILURE);
	}

	return (path);
}
void execute_and_free(char *cd_path, char **ux_commandz1, char *exec)
{
	strcpy(cd_path, "/usr/bin/");
	strcat(cd_path, exec);
	if (execve(cd_path, ux_commandz1, environ) == -1)
	{
	perror("Command execution was unsuccessful");
	exit(EXIT_FAILURE);
	}

	free(cd_path);
	free(ux_commandz1);
}
