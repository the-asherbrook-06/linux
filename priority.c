#include <stdio.h>

struct process {
    int pid, pr, bt, stt, ft, wt;
} t, ps[10] = {0};

int nj, i, j;

void getinput();
void priority();
void disp_state();

void main() {
    printf("Enter the number of Jobs : ");
    scanf("%d", &nj);
    getinput();
    priority();
    disp_state();
}

void getinput() {
    for (i = 0; i < nj; i++) {
        ps[i].pid = i;
        printf("\nEnter the burst time and priority of job %d: ", i + 1);
        scanf("%d %d", &ps[i].bt, &ps[i].pr);
    }
}

void priority() {
    // Sort based on priority (lower value = higher priority)
    for (i = 0; i < nj - 1; i++) {
        for (j = i + 1; j < nj; j++) {
            if (ps[i].pr > ps[j].pr) {
                t = ps[i];
                ps[i] = ps[j];
                ps[j] = t;
            }
        }
    }

    // Calculate start time, finish time, and waiting time
    for (i = 0; i < nj; i++) {
        if (i == 0) {
            ps[i].stt = 0;
            ps[i].wt = 0;
        } else {
            ps[i].stt = ps[i - 1].ft;
            ps[i].wt = ps[i].stt;
        }
        ps[i].ft = ps[i].stt + ps[i].bt;
    }
}

void disp_state() {
    int tw = 0, tt = 0;
    float aw, ata;

    printf("\n\tMETHOD PRIORITY SCHEDULING\n\n");
    printf("ID\tPRIORITY\tBURST TIME\tSTART\tFINISH\tWAIT\n");

    for (i = 0; i < nj; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t%d\t%d\n",
               ps[i].pid + 1, ps[i].pr, ps[i].bt, ps[i].stt, ps[i].ft, ps[i].wt);
        tw += ps[i].wt;
        tt += ps[i].ft;
    }

    aw = (float)tw / nj;
    ata = (float)tt / nj;
    printf("\nAVG WAITING TIME = %f", aw);
    printf("\nAVG TURN AROUND TIME = %f\n", ata);
}
