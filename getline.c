#include "main.h"
/**
 * main - used to create a command shell enviroment
 * @ac: argument count
 * @argv: arguments
 *
 * Return: 0 always
 */
int main(int *ac, char *argv[])
{
	char *prompt = NULL;
	size_t lenVar = 0;

	pid_t pid;

	printf("$ ");
	while (getline(&prompt, &lenVar, stdin) != EOF)
	{
		int len_prompt = strlen(prompt);

		prompt[len_prompt - 1] = '\0';

		pid = fork();

		if (pid == 0)
		{
			char *cmd[] = {prompt, NULL};

			int var = execve(cmd[0], cmd, NULL);
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
		printf("$ ");
	}
	free(prompt);
	return (0);
}