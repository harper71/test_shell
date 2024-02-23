#include "main.h"

int main(void)
{
	char cmd[] = "/usr/bin/ls";

	char *argv[] = {"/usr/bin/ls", NULL};
	char *env[] = {NULL};

	printf("start the exection of %s\n", cmd);
	printf("==================================================\n");

	if (execve(argv[0], argv, env) == -1)
	{
		perror("error when executing this command\n");
	}

	printf("opps something when wrong\n");
}
