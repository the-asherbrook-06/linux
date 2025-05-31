// zombie.c
#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t t = fork();
  
  if (t < 0) {
    printf("Fork failed");
    return 1;
  }
  else if (t == 0) {
    printf("Child having PID: %d\n", getpid());
    return 0;
  }
  else {
    printf("Parent having id %d\n", getpid());
    sleep(5);
  }
}
