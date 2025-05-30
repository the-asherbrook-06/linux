#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>      // For ctime()
#include <stdlib.h>    // For exit()
#include <string.h>    // Optional: for strerror()
#include <errno.h>     // Optional: for errno

int main(int argc, char *argv[]) {
    struct stat file;

    if (argc != 2) {
        printf("Usage: ./a.out <filename>\n");
        return -1;
    }

    if (stat(argv[1], &file) == -1) {
        perror("Error getting file info");
        return -1;
    }

    printf("User ID: %d\n", file.st_uid);
    printf("Group ID: %d\n", file.st_gid);
    printf("Block Size: %ld\n", file.st_blksize);
    printf("Blocks Allocated: %ld\n", file.st_blocks);
    printf("Inode No.: %lu\n", file.st_ino);
    printf("Last Accessed: %s", ctime(&file.st_atime));
    printf("Last Modified: %s", ctime(&file.st_mtime));
    printf("File Size: %ld bytes\n", file.st_size);
    printf("No. of Links: %ld\n", file.st_nlink);

    // Permissions
    printf("Permissions: ");
    printf((S_ISDIR(file.st_mode)) ? "d" : "-");
    printf((file.st_mode & S_IRUSR) ? "r" : "-");
    printf((file.st_mode & S_IWUSR) ? "w" : "-");
    printf((file.st_mode & S_IXUSR) ? "x" : "-");
    printf((file.st_mode & S_IRGRP) ? "r" : "-");
    printf((file.st_mode & S_IWGRP) ? "w" : "-");
    printf((file.st_mode & S_IXGRP) ? "x" : "-");
    printf((file.st_mode & S_IROTH) ? "r" : "-");
    printf((file.st_mode & S_IWOTH) ? "w" : "-");
    printf((file.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    // File type
    if (S_ISREG(file.st_mode))
        printf("File Type: Regular File\n");
    else if (S_ISDIR(file.st_mode))
        printf("File Type: Directory\n");
    else
        printf("File Type: Other\n");

    return 0;
}

