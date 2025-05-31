// orphan.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  pid_t pid = fork();
  
  if (pid < 0) {
    printf("Fork Failed");
    return 1;
  }
  else if (pid > 0) {
    printf("I'm a Parent with PID: %d\t", getpid());
    printf("My Child has a PID: %d\n", pid);
  }
  else {
    sleep(5);
    printf("I'm a Child with PID: %d\t", getpid());
    printf("My Parent has PID: %d\n", getppid());
  }
  return 0;
}
