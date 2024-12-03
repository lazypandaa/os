#include <stdio.h>

int main() {
    int n, quantum, i, time = 0, flag = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n], remaining_bt[n], wt[n], tat[n];

    printf("Enter burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1;   // Assign process numbers
        remaining_bt[i] = bt[i]; // Initialize remaining burst times
        wt[i] = 0;             // Initialize waiting times
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    float x=0,y=0;
    // Round Robin Scheduling
    while (1) {
        flag = 0; // Check if all processes are done
        for (i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                flag = 1; // At least one process is not finished
                if (remaining_bt[i] > quantum) {
                    time += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    time += remaining_bt[i];
                    wt[i] = time - bt[i];
                    remaining_bt[i] = 0;
                    x=wt[i];
                }
            }
        }
        if (flag == 0)
            break; // Exit if all processes are done
    }

    // Calculate Turnaround Time (TAT)
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        y=tat[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
      printf("Avarage wt is%f\n",x/n);
    printf("Avarage tat is%f",y/n);
    return 0;
}

//Round Robin