#include <stdio.h>

struct process {
    int pid, at, bt, st, ft, wt, tat;
} ps[10];

int nj;

void getinput();
void fcfs();
void disp();

int main() {
    printf("Enter the number of jobs: ");
    scanf("%d", &nj);
    getinput();
    fcfs();
    disp();
    return 0;
}

void getinput() {
    for (int i = 0; i < nj; i++) {
        ps[i].pid = i + 1;
        printf("1Enter arrival time & burst time for job %d: ", i + 1);
        scanf("%d %d", &ps[i].at, &ps[i].bt);
    }
}

void fcfs() {
    struct process temp;

    for (int i = 0; i < nj - 1; i++) {
        for (int j = i + 1; j < nj; j++) {
            if (ps[i].at > ps[j].at) {
                temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }
    }

    // Scheduling calculations
    for (int i = 0; i < nj; i++) {
        if (i == 0) {
            ps[i].st = ps[i].at;
        } else {
            ps[i].st = (ps[i - 1].ft > ps[i].at) ? ps[i - 1].ft : ps[i].at;
        }
        ps[i].ft = ps[i].st + ps[i].bt;
        ps[i].wt = ps[i].st - ps[i].at;
        ps[i].tat = ps[i].ft - ps[i].at;
    }
}

void disp() {
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("\n\t\tMETHOD FCFS\n\n");
    printf("ID\tARRIVAL\tBURST\tSTART\tFINISH\tWAIT\tTAT\n");

    for (int i = 0; i < nj; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               ps[i].pid, ps[i].at, ps[i].bt, ps[i].st, ps[i].ft, ps[i].wt, ps[i].tat);
        total_wt += ps[i].wt;
        total_tat += ps[i].tat;
    }

    avg_wt = (float) total_wt / nj;
    avg_tat = (float) total_tat / nj;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
}
