// receiver.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    mkfifo(fifo, 0666); // Create the named pipe (only once)

    int fd = open(fifo, O_RDONLY); // Open for reading
    char buffer[100];

    read(fd, buffer, sizeof(buffer));
    printf("Received: %s", buffer);
    close(fd);

    return 0;
}
