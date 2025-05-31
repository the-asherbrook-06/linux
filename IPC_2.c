#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int fd[2], n;
  char buffer[100];
  pid_t p;
  
  pipe(fd);
  p = fork();
  
  if (p < 0) {
    printf("Fork failed\n");
    return 1;
  } 
  else if (p > 0) {
    printf("Parent passing value to child\n");
    write(fd[1], "hello\n", 6);
    close(fd[1]);
    wait(NULL);
  } 
  else {
    printf("Child receiving value from parent: ");
    fflush(stdout);
    close(fd[1]);
    n = read(fd[0], buffer, 100);
    write(1, buffer, n);
  }
  return 0;
}

