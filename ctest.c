#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    printf("This program should print 1,2,3 in order.\n");
    printf("If it does, you're good to go with Lambda School C.\n\n");
    
    printf("1\n");

    if (fork() == 0) {
        printf("2\n");
        exit(0);
    }

    wait(NULL);

    printf("3\n");

    return 0;
}