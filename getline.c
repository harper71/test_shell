#include "main.h"
/**
 * main - used to create a command shell enviroment
 * @ac: argument count
 * @argv: arguments
 *
 * Return: 0 always
 */
int main(int *ac, char *av[])
{
	char *prompt = NULL, *str_cpy = NULL;

	char *delm = " \n";

	size_t lenVar = 0;

	char *cmd[3];

	int var, len_prompt, i, argc;

	char *token = NULL, **argv = NULL;

	pid_t pid;

	printf("$ ");

	while (getline(&prompt, &lenVar, stdin) != EOF)
	{
		len_prompt = strlen(prompt);
		prompt[len_prompt - 1] = '\0';
		str_cpy = strdup(prompt);

		token = strtok(prompt, delm);
		while (token)
		{
			token = strtok(NULL, delm);
			argc++;
		}
		argv = malloc(sizeof(char *) * argc);

		token = strtok(str_cpy, delm);

		while(token)
		{
			argv[i] = token;
			token = strtok(NULL, delm);
			i++;
		}

		while (argv[i])
		{
			pid = fork();
			if (pid == 0)
			{
				cmd[0] = argv[0];
				cmd[1] = argv[1];
				cmd[2] = NULL;
				var = execve(cmd[0], cmd, NULL);
				if (var == -1)
				{
					printf("%s: no such directory\n", argv[0]);
				}
				break;
			}
			else
			{
				wait(NULL);
			}
		}
		printf("$ ");
	}
	free(prompt);
	return (0);
}
