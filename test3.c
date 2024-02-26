#include "main.h"

int main(int ac, char *av[])
{
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;

	char *delm = " \n";

	size_t n = 0;

	pid_t pid;

	struct stat file;

	int arg = 0, i = 0, var;

	char **argv = NULL;

	printf("$ ");
	if (getline(&cmd, &n, stdin) == -1)
	{
		return -1;
	}

	cmd_cpy = strdup(cmd);

	while(cmd[i])
	{
		if(cmd[i] == '\n')
		{
			printf("\\n ---> input has %ld characters\n", strlen(cmd));
		}
		else
			printf("%c", cmd[i]);
		i++;
	}
	token = strtok(cmd, delm);

	while(getline(&cmd, &n, stdin) != EOF)
	{
		while(token != NULL)
		{
			char dir[] = "/usr/bin/";
			char path[strlen(dir) + strlen(token) + 1];
			strcpy(path, dir);
			strcat(path, token);
			arg++;

			if (stat(path, &file) == 0)
			{
				pid = fork();
				if (pid == 0)
				{
					char *mycmd[] = {path, NULL};

					int var = execve(mycmd[0], mycmd, NULL);

					if (var == -1)
					{
						printf("can't execute this command.\n");
					}
					token = strtok(NULL, delm);
				}
				else
				{
					wait(NULL);
				}
			}
			else
			{
				printf("%s not found\n", token);
			}
			arg++;
		}
		printf("$ ");
	}
	printf("%d\n", arg);
	free(cmd);
	free(cmd_cpy);
	return 0;
}
