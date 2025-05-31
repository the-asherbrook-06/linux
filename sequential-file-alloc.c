#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], i, st, j, len, c, k;

    // Initialize all blocks as free
    for(i = 0; i < 50; i++)
        f[i] = 0;

    do {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d%d", &st, &len);

        if (st < 0 || st + len > 50) {
            printf("Invalid block range. Try again.\n");
            continue;
        }

        int allocated = 1;
        for(j = st; j < (st + len); j++) {
            if(f[j] == 1) {
                printf("Block %d is already allocated. Cannot allocate file.\n", j);
                allocated = 0;
                break;
            }
        }

        if (allocated) {
            for(j = st; j < (st + len); j++) {
                f[j] = 1;
                printf("%d -> %d\n", j, f[j]);
            }
            printf("File successfully allocated.\n");
        }

        printf("\nDo you want to enter more files? (Yes: 1 / No: 0): ");
        scanf("%d", &c);

    } while(c == 1);

    printf("Exiting program.\n");
    return 0;
}

