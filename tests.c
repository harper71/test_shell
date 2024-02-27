#include "main.h"

int main(int ac, char *av[])
{
	char *token, *prompt, *cmd[2];
	int i, var, len_prompt;
	size_t n = 0;

	struct stat file;

	pid_t pid;

	printf("$ ");
	while (getline(&prompt, &n, stdin) != -1)
	{
		len_prompt = strlen(prompt);

		prompt[len_prompt - 1] = '\0';
		token = strtok(prompt, " \n");
		while(token != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				cmd[0] = token;
				cmd[1] = NULL;

				var = execve(cmd[0], cmd, NULL);
				if (var == -1)
				{
					printf("%s: not a directory\n", av[0]);
				}
				break;
			}
			else
			{
				wait(NULL);

			}
			token = strtok(NULL, " \n");
			break;
		}
		printf("$ ");
	}
	free(prompt);
	return (0);
}
