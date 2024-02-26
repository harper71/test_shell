#include "main.h"

int main(int ac, char *av[])
{
	char *cmd, *token;

	size_t n = 0;

	struct stat file;

	int arg = 0;

	printf("$ ");
	if (getline(&cmd, &n, stdin) == -1)
	{
		return -1;
	}

	token = strtok(cmd, " \n");

	while(token != NULL)
	{
		char dir[] = "/usr/bin/";
		char path[strlen(dir) + strlen(token) + 1];

		sprintf(path, "%s%s", dir, token);
		if (stat(path, &file) == 0)
		{
			char *mycmd[] = {path, NULL};

			int var = execve(mycmd[0], mycmd, NULL);

			if (var == -1)
			{
			printf("can't execute this command.\n");
			}
		}
		else
		{
			printf("%s not found\n", token);
		}
		token = strtok(NULL, " \n");
		arg++;
	}
	printf("%d\n", arg);
	free(cmd);
	return 0;
}
