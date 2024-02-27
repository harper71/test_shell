#include "main.h"

int main(int argc, char *argv[]) {
    char *cmd = NULL;
    size_t n = 0;
    pid_t pid;
    struct stat file;
    char *delm = " \n";

    printf("$ ");
    while (getline(&cmd, &n, stdin) != -1) {
        char *token = strtok(cmd, delm);

        while (token != NULL) {
            char dir[] = "/usr/bin/";
            char path[strlen(dir) + strlen(token) + 1];
            strcpy(path, dir);
            strcat(path, token);

            if (stat(path, &file) == 0) {
                pid = fork();
                if (pid == -1) {
                    perror("fork");
                    exit(EXIT_FAILURE);
                } else if (pid == 0) { // Child process
                    char *mycmd[] = {path, NULL};
                    execve(mycmd[0], mycmd, NULL);
                    // If execve returns, it means it failed
                    perror("execve");
                    exit(EXIT_FAILURE);
                } else { // Parent process
                    wait(NULL);
                }
            } else {
                printf("%s not found\n", token);
            }

            token = strtok(NULL, delm);
        }

        printf("$ ");
    }

    free(cmd);
    return 0;
}
