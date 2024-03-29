#include "shell.h"

/**
 * main - The main pnt of entry, to the code.
 * Description: ux interface of Eshell.
 * Return: 0, if it's a succes.
 */


int main(void)
{
	int isize = MAX_INPUT_SIZE;
	char commds[MAX_INPUT_SIZE];
	int ext_stat;
	char **envp = environ;

	while (1)
	{
		printf("Eshell$ ");
		fgets(commds, isize, stdin);

		commds[strlen(commds) - 1] = '\0';

		/* to be creating an exit cond. the user*/
		if (strcmp(commds, "exit") == 0)
		{
			printf("logging out...\n");
			break;
		}
		else if (strncmp(commds, "exit ", 5) == 0)
		{
			ext_stat = atoi(commds + 5);

			exit(ext_stat);
		}
		else if (strcmp(commds, "env") == 0)
		{
			while (*envp)
			{
				printf("%s\n", *envp);
				envp++;
			}
		}

		execute_pt(commds);
	}
	return (0);
}
