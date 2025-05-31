#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_function(void *args);
int i, n, j;

int main() {
    char *m = "5";
    pthread_t a;
    void *result;

    pthread_create(&a, NULL, thread_function, m);
    pthread_join(a, &result);
    printf("Thread created and joined\n");

    for(j = 20; j < 25; j++) {
        printf("%d\t", j);
        sleep(1);
    }

    printf("\nThread returned %s\n", (char *)result);
    return 0;
}

void *thread_function(void *args) {
    int sum = 0;
    n = atoi((char *)args);
    for(i = 0; i < n; i++) {
        printf("%d\t", i);
        sleep(1);
    }
    printf("\n");
    pthread_exit("Done");
}

