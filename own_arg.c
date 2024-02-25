#include "main.h"

int main(int ac, char *av[])
{
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;

	char *delm = " \n";

	size_t n = 0;

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

	while(token != NULL)
	{
		char dir[] = "usr/bin/";
		char path[strlen(dir) + strlen(token) + 1];
		printf("%s\n", token);
		strcpy(path, dir);
		strcat(path, token);
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
		token = strtok(NULL, delm);
		arg++;
		
	}
	printf("%d\n", arg);



	free(cmd);
	free(cmd_cpy);
	return 0;
}
