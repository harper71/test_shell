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
		char *mycmd[] = {token[0], token[1], NULL};

		int var = execve(mycmd[0], mycmd, NULL);

		if (var == -1)
		{
			printf("can't execute this command.\n");
		}
		token = strtok(NULL, " \n");
		arg++;
	}
	printf("%d\n", arg);
	free(cmd);
	return 0;
}
