#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  
  if(pid < 0) {
    printf("Fork failed\n");
    return 1;
  }
  else if(pid == 0)
    printf("Hello from the child process with PID: %d\n", getpid());
  else
    printf("Hello from the parent process with PID: %d\n", getpid());
  return 0;
}
