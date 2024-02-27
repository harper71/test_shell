#include "main.h"

int main(void)
{
	char *token = NULL, *prompt = NULL, *cpy_str = NULL;
	char *delm = " \n";
	int argc = 0, i = 0;
	size_t len_prompt = 0;
	char **argv;


	printf("$ ");
	int checks = getline(&prompt, &len_prompt, stdin);
	if (checks == -1)
	{
		printf("unable to get user output");
	}

	cpy_str = strdup(prompt);

	token = strtok(prompt, delm);
	while (token)
	{
		token = strtok(NULL, " ");
		argc++;
	}
	printf("%d\n", argc);

	argv = malloc(sizeof(char *) * argc);
	token = strtok(cpy_str, delm);

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delm);
		i++;
	}
	argv[i] = NULL;

	i = 0;
	while (argv[i])
	{
		char *cmd[] = {argv[0], argv[1], NULL};
		int var = execve(cmd[0], cmd, NULL);

		if (var == -1)
		{
			printf("%s command not found\n", argv[i]);
		}
		printf("%s\n", argv[i++]);
		printf("%d", i);
	}
	if (prompt = "exit")
	{
		return -1;
	}
	free(prompt);
	free(cpy_str);
	free(argv);
	return (0);
}

