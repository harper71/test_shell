#include "main.h"

int main(void)
{
	int n = 0;
	
	int pid;

	printf("before fork: %d\n", n);
	sleep(2);

	pid = fork();

	printf("After fork: %d PID: %u\n", n, pid);
	exit(0);
}
