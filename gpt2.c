#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int ac, char *argv[]) {
    char *prompt = NULL, *str_cpy = NULL;
    char *delm = " \n";
    size_t lenVar = 0;
    int len_prompt, i, argc;
    char *token = NULL, **cmd = NULL;
    pid_t pid;

    printf("$ ");

    while (getline(&prompt, &lenVar, stdin) != EOF) {
        len_prompt = strlen(prompt);
        prompt[len_prompt - 1] = '\0';
        str_cpy = strdup(prompt);

        argc = 0; // Reset argc for each prompt
        token = strtok(prompt, delm);
        while (token) {
            token = strtok(NULL, delm);
            argc++;
        }

        cmd = malloc(sizeof(char *) * (argc + 1)); // +1 for NULL terminator
        if (cmd == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        token = strtok(str_cpy, delm);
        i = 0; // Initialize i
        while (token) {
            cmd[i] = token;
            token = strtok(NULL, delm);
            i++;
        }
        cmd[i] = NULL; // NULL terminate the cmd array

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child process
            execve(cmd[0], cmd, NULL);
            // If execvp returns, it must have failed
            perror("execvp");
            exit(EXIT_FAILURE);
        } else { // Parent process
            wait(NULL);
        }

        printf("$ ");
        free(cmd);
    }
    free(prompt);
    return 0;
}
