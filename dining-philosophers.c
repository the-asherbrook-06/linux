#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];

void *philos(void *);
void eat(int);

int main() {
    int i, n[5];
    pthread_t T[5];

    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < 5; i++) {
        n[i] = i;
        pthread_create(&T[i], NULL, philos, (void *)&n[i]);
    }

    for (i = 0; i < 5; i++)
        pthread_join(T[i], NULL);

    return 0;
}

void *philos(void *n) {
    int ph = *(int *)n;

    printf("[%d] Wants to eat...\n", ph);
    printf("[%d] Tries picking up left chopstick...\n", ph);
    sem_wait(&chopstick[ph]);
    printf("[%d] Picked up left chopstick\n", ph);

    printf("[%d] Tries picking up right chopstick...\n", ph);
    sem_wait(&chopstick[(ph + 1) % 5]);
    printf("[%d] Picked up right chopstick\n", ph);

    eat(ph);
    sleep(2);

    printf("[%d] Finished eating\n", ph);

    sem_post(&chopstick[(ph + 1) % 5]);
    printf("[%d] Puts down right chopstick\n", ph);

    sem_post(&chopstick[ph]);
    printf("[%d] Puts down left chopstick\n", ph);

    pthread_exit(NULL);
}

void eat(int ph) {
    printf("[%d] Begins to eat\n", ph);
}
