// orphan.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t p = fork();

    if (p == 0) {
        // Child process
        sleep(5);  // Ensure parent terminates before child prints
        printf("I am child having PID %d\n", getpid());
        printf("My parent PID is %d\n", getppid());
    } 
    else if (p > 0) {
        // Parent process
        printf("I am parent having PID %d\n", getpid());
        printf("My child PID is %d\n", p);
        exit(0);  // Parent exits early, making child orphan
    } 
    else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}
