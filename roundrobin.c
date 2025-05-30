#include <stdio.h>

void main() {
    int p[30], bt[30], i, n, d;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the CPU burst time for process %d: ", i + 1);
        p[i] = i + 1;
        scanf("%d", &bt[i]);
    }

    d = n;

    while (d != 0) {
        for (i = 0; i < n; i++) {
            if (p[i] != 0) {
                if (bt[i] > 5) {
                    printf("\nProcess %d is executed for 5 sec", p[i]);
                    bt[i] = bt[i] - 5;
                } else {
                    printf("\nProcess %d is executed for %d sec (Completed)", p[i], bt[i]);
                    bt[i] = 0;
                    p[i] = 0;
                    d--;
                }
            }
        }
    }
}
