#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
        char buffer[1024];
	char *current_arg = NULL;

	for (int i = 1; argv[i] != NULL; ++i) {
		write(STDOUT_FILENO, current_arg, strlen(current_arg));
		write(STDOUT_FILENO, "\n", 1);
    	}

	write(1, "$ ", 2);
	fflush(stdout);
	
	ssize_t byte_read = 0;
    	char ch;
    	int index = 0;

    	while (byte_read < sizeof(buffer) - 1 && read(STDIN_FILENO, &ch, 1) == 1 && ch != '\n') {
        buffer[index++] = ch;
        byte_read++;
    	}
	buffer[byte_read] ='\0';

	write(1, buffer, byte_read);
	write(STDOUT_FILENO, "\n", 1);
        return (0);

}
