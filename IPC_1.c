#include <stdio.h>
#include <string.h>

int main() {
  FILE *rd;
  char buffer[50];
  sprintf(buffer, "name first");

  rd = popen("wc -c", "w");
  if (rd == NULL) {
    perror("popen failed");
    return 1;
  }

  fwrite(buffer, sizeof(char), strlen(buffer), rd);
  pclose(rd);

  return 0;
}

