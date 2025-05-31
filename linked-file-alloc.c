#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], i, st, j, len, c;

    for(i = 0; i < 50; i++)
        f[i] = 0;

    do {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d%d", &st, &len);

        if(st + len > 50) {
            printf("File exceeds disk size. Try again.\n");
            continue;
        }

        int allocated = 1;
        for(j = st; j < (st + len); j++) {
            if(f[j] == 0) {
                f[j] = 1;
                printf("%d -> %d\n", j, f[j]);
            } else {
                printf("Block %d already allocated!\n", j);
                allocated = 0;
                break;
            }
        }

        if(allocated)
            printf("File successfully allocated to disk.\n");

        printf("\nDo you want to enter more files? (Yes: 1 / No: 0): ");
        scanf("%d", &c);

    } while(c == 1);

    printf("Exiting program.\n");
    return 0;
}

