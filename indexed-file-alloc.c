#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], i, k, j, inde[50], n, c, p;

    // Initialize all blocks as free
    for(i = 0; i < 50; i++)
        f[i] = 0;

    while(1) {
        printf("\nEnter index block: ");
        scanf("%d", &p);

        if(f[p] == 0) {
            f[p] = 1;
            printf("Enter number of blocks for the file: ");
            scanf("%d", &n);

            printf("Enter the blocks:\n");
            for(i = 0; i < n; i++)
                scanf("%d", &inde[i]);

            // Check if all blocks are free
            int allocated = 1;
            for(i = 0; i < n; i++) {
                if(f[inde[i]] == 1) {
                    printf("Block %d already allocated. Try again.\n", inde[i]);
                    allocated = 0;
                    break;
                }
            }

            if(allocated) {
                for(j = 0; j < n; j++)
                    f[inde[j]] = 1;

                printf("\nFile allocated using indexed allocation.");
                printf("\nIndex block: %d", p);
                printf("\nBlocks allocated:");
                for(k = 0; k < n; k++)
                    printf("\n %d -> %d", p, inde[k]);
            }
        } else {
            printf("Block %d is already allocated. Try another.\n", p);
        }

        printf("\n\nDo you want to enter more files? (Yes: 1 / No: 0): ");
        scanf("%d", &c);
        if(c == 0)
            break;
    }

    printf("Exiting program.\n");
    return 0;
}

