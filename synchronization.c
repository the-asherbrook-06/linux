#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *fun1();
void *fun2();

int shared = 1;
pthread_mutex_t lock;

int main() {
  pthread_mutex_init(&lock, NULL);
  pthread_t thread1, thread2;
  
  pthread_create(&thread1, NULL, fun1, NULL);
  pthread_create(&thread2, NULL, fun2, NULL);
  
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  
  printf("Final value of Shared Variable; %d\n", shared);
}

void *fun1() {
  int x;
  
  printf("[1] locking...\n");
  pthread_mutex_lock(&lock);
  printf("[1] locked\n");
  
  x = shared;
  printf("[1] X: %d\n", x);
  x++;
  printf("[1] X (local): %d\n", x);
  
  sleep(1);
  
  shared = x;
  printf("[1] value updated to shared variable\n");
  pthread_mutex_unlock(&lock);
  printf("[1] unlocked...\n");
}

void *fun2() {
  int y;
  
  printf("[2] locking...\n");
  pthread_mutex_lock(&lock);
  printf("[2] locked\n");
  
  y = shared;
  printf("[2] Y: %d\n", y);
  y++;
  printf("[2] Y (local): %d\n", y);
  
  sleep(1);
  
  shared = y;
  printf("[2] value updated to shared variable\n");
  pthread_mutex_unlock(&lock);
  printf("[2] unlocked...\n");
}


