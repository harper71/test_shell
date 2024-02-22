#include "main.h"
// if you call fork ones you get 2^fork process
int main(int argc, char *argv[])
{

    fork();
    fork();
    fork();
    fork();
    
    // fork();
    // id in the child process is always 0

    printf("hello your process id is %u  and your parent process id is %u\n", getpid(), getppid());

    return 0;



}
