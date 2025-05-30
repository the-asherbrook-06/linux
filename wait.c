#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid = fork();
  
  if(pid < 0) {
    printf("Fork Failed");
    return 1;
  }
  else if(pid == 0) {
    printf("Child with Odd Numbers: ");
    for(int i = 1; i < 10; i=i+2)
      printf("%d ", i);
    printf("Child ends\n");
  }
  else {
    wait(NULL);
    printf("Parent with Even Numbers: ");
    for(int i = 0; i < 10; i=i+2)
      printf("%d ", i);
    printf("Parent ends\n");
  }
  return 0;
}
