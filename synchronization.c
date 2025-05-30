#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// Shared variable
int shared = 1;

// Mutex declaration
pthread_mutex_t l;

// Thread function declarations
void *fun1(void *arg);
void *fun2(void *arg);

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex
    pthread_mutex_init(&l, NULL);

    // Create two threads
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final value of the shared variable
    printf("Final value of shared is %d\n", shared);

    // Destroy the mutex (good practice)
    pthread_mutex_destroy(&l);

    return 0;
}

// Thread 1 function: increment shared variable
void *fun1(void *arg) {
    int x;

    printf("Thread1 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("Thread1 acquired lock\n");

    x = shared;
    printf("Thread1 reads the value of shared variable as %d\n", x);

    x++; // increment
    printf("Local updation by Thread1: %d\n", x);

    sleep(1); // simulate delay

    shared = x;
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);

    pthread_mutex_unlock(&l);
    printf("Thread1 released the lock\n");

    return NULL;
}

// Thread 2 function: decrement shared variable
void *fun2(void *arg) {
    int y;

    printf("Thread2 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("Thread2 acquired lock\n");

    y = shared;
    printf("Thread2 reads the value as %d\n", y);

    y--; // decrement
    printf("Local updation by Thread2: %d\n", y);

    sleep(1); // simulate delay

    shared = y;
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);

    pthread_mutex_unlock(&l);
    printf("Thread2 released the lock\n");

    return NULL;
}
