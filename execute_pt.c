#include "shell.h"

/**
 * execute_pt - Function to execute a prompt.
 * @uput: Ptr to a character string input by the user.
 * Return: void
 */
void execute_pt(const char *uput)
{
	pid_t child_pid;
	char **ux_commandz1, *exec, *cd_path;
	int w = 0, arCd = 0;
	char *env[] = {NULL};
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

		token = strtok((char *)uput, " ");
		while (token != NULL)
		{
			ux_commandz1[w] = token;
			token = strtok(NULL, " ");
			w++;
		}
		ux_commandz1[w] = NULL;

		exec = ux_commandz1[0];
		cd_path = "/bin/";
		cd_path = malloc(strlen(cd_path) + strlen(exec) + 1);
		if (cd_path == NULL)
		{
			perror("memory allocation was unsuccessful");
			exit(EXIT_FAILURE);
		}
		strcpy(cd_path, "/usr/bin/");
		strcat(cd_path, exec);

		if (execve(cd_path, ux_commandz1, env) == -1)
		{
			perror("Command execution was unsuccessful");
			exit(EXIT_FAILURE);
		}
		free(cd_path);
		free(ux_commandz1);
	}
	else
	{
		waitpid(child_pid, &arCd, 0);
	}
}
