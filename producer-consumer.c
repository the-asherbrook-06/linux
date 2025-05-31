#include <stdio.h>
#include <stdlib.h>

int full = 0, empty = 5, mutex = 1;
int buffer[5], in = 0, out = 0;

void wait(int *s) {
    while (*s <= 0); // busy wait (not ideal in real systems)
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    int nextp;
    printf("\nProducer\n");
    wait(&empty);
    wait(&mutex);
    nextp = rand() % 10 + 1;  // Generate item
    buffer[in] = nextp;
    printf("Produced item: %d\n", nextp);
    in = (in + 1) % 5;
    signal(&mutex);
    signal(&full);
    printf("Full = %d\tEmpty = %d\n", full, empty);
}

void consumer() {
    int nextc;
    printf("\nConsumer\n");
    wait(&full);
    wait(&mutex);
    nextc = buffer[out];
    printf("Consumed item: %d\n", nextc);
    out = (out + 1) % 5;
    signal(&mutex);
    signal(&empty);
    printf("Full = %d\tEmpty = %d\n", full, empty);
}

void main() {
    int choice;
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Both\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (empty == 0)
                    printf("Producer has to wait (Buffer Full)\n");
                else
                    producer();
                break;
            case 2:
                if (full == 0)
                    printf("Consumer has to wait (Buffer Empty)\n");
                else
                    consumer();
                break;
            case 3:
                if (empty == 0)
                    printf("Producer has to wait (Buffer Full)\n");
                else
                    producer();

                if (full == 0)
                    printf("Consumer has to wait (Buffer Empty)\n");
                else
                    consumer();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
