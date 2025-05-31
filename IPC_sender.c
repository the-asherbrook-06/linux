// sender.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    mkfifo(fifo, 0666); // Create the named pipe (only once)

    int fd = open(fifo, O_WRONLY); // Open for writing
    char message[] = "Hello from sender!\n";
		
    write(fd, message, sizeof(message));
    close(fd);

    return 0;
}
