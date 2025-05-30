#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid = fork();
  
  if(pid < 0) {
    printf("Fork Failed\n");
    return 1;
  }
  else if(pid == 0) {
    printf("Child Process: ");
    execl("/bin/date", "date", NULL);
    return 0;
  }
  else {
    wait(NULL);
    printf("Child Terminated\n");
    return 0;
  }
}
