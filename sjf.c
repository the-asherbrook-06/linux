#include <stdio.h>

struct process {
    int p, bt, st, ft, wt, tat;
} t, ps[10];

int nj;

void getinput();
void SJFS();
void disp();

int main() {
    printf("Enter No of jobs: ");
    scanf("%d", &nj);
    getinput();
    SJFS();
    disp();
    return 0;
}

void getinput() {
    for (int i = 0; i < nj; i++) {
        ps[i].p = i + 1;
        printf("Enter the Burst time of job %d: ", i + 1);
        scanf("%d", &ps[i].bt);
    }
}

void SJFS() {
    // Sort by Burst Time
    for (int i = 0; i < nj - 1; i++) {
        for (int j = i + 1; j < nj; j++) {
            if (ps[i].bt > ps[j].bt) {
                t = ps[i];
                ps[i] = ps[j];
                ps[j] = t;
            }
        }
    }

    // Calculate start, finish, wait, turnaround time
    for (int i = 0; i < nj; i++) {
        if (i == 0) {
            ps[i].st = 0;
        } else {
            ps[i].st = ps[i - 1].ft;
        }

        ps[i].ft = ps[i].st + ps[i].bt;
        ps[i].wt = ps[i].st;  // No arrival time considered
        ps[i].tat = ps[i].ft; // No arrival time considered
    }
}

void disp() {
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("\n\t\tMETHOD SJFS (NON-PREEMPTIVE)\n\n");
    printf("ID\tBURST TIME\tSTART\tFINISH\tWAIT\tTAT\n");

    for (int i = 0; i < nj; i++) {
        printf("%d\t%d\t\t%d\t%d\t%d\t%d\n", ps[i].p, ps[i].bt, ps[i].st, ps[i].ft, ps[i].wt, ps[i].tat);
        total_wt += ps[i].wt;
        total_tat += ps[i].tat;
    }

    avg_wt = (float)total_wt / nj;
    avg_tat = (float)total_tat / nj;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
}
