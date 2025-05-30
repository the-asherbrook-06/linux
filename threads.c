#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// Function prototype
void *thread_function(void *arg);

int main() {
    char *m = "5"; // String to be converted to int inside thread
    pthread_t a_thread; // Thread declaration
    void *result; // For capturing the return value of the thread

    // Create a thread and pass argument
    if (pthread_create(&a_thread, NULL, thread_function, m) != 0) {
        perror("Thread creation failed");
        exit(1);
    }

    // Wait for the thread to complete
    if (pthread_join(a_thread, &result) != 0) {
        perror("Thread join failed");
        exit(1);
    }

    printf("Thread joined\n");

    // Main thread prints numbers
    for (int j = 20; j < 25; j++) {
        printf("%d\n", j);
        sleep(1);
    }

    printf("Thread returned: %s\n", (char *)result);

    return 0;
}

// Thread function
void *thread_function(void *arg) {
    int n = atoi((char *)arg); // Convert argument to integer

    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
        sleep(1);
    }

    // Return a string from the thread
    pthread_exit("Done");
}
