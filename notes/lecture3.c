#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("I'm the parent process, and my pid is %d!\n", getpid());

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("I'm the child process, and my pid is %d!\n", getpid());
        exit(0);
    }

    printf("I'm the parent again, and I just spawned child %d!\n", pid);

    printf("Waiting...\n");
    wait(NULL); // wait for child process to die

    printf("WAT: pid: %d\n", getpid());

    return 0;
}