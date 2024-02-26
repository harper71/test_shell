#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *cmd = NULL;
    size_t n = 0;

    struct stat file;

    printf("$ ");
    if (getline(&cmd, &n, stdin) == -1) {
        perror("Error reading input");
        return 1;
    }

    char *token = strtok(cmd, " \n"); // Tokenizing the input by space and newline

    while (token != NULL) {
        char dir[] = "/usr/bin/";
        char path[strlen(dir) + strlen(token) + 1];
        sprintf(path, "%s%s", dir, token); // Constructing the full path

        if (stat(path, &file) == 0) {
            char *mycmd[] = {path, NULL};
            int var = execve(mycmd[0], mycmd, NULL);

            if (var == -1) {
                perror("execve"); // Print error if execve fails
                return 1;
            }
        } else {
            printf("%s not found\n", token);
        }

        token = strtok(NULL, " \n"); // Move to the next token
    }

    free(cmd); // Free allocated memory
    return 0;
}
