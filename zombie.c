// zombie.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t t;
    t = fork();

    if (t == 0) {
        // Child process
        printf("Child having id %d exiting\n", getpid());
        exit(0); // Child exits immediately
    } else {
        // Parent process
        printf("Parent having id %d sleeping\n", getpid());
        sleep(50); // Parent sleeps, not collecting child exit status
    }

    return 0;
}
