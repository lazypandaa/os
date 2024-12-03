#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int burstTime[n], waitingTime[n], turnAroundTime[n];
    
    printf("Enter burst times for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }
    waitingTime[0] = 0;
    int xy=0,xz=0;
    for(i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        xy+=waitingTime[i];
    }
    for(i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
        xz+=turnAroundTime[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }
printf("Average waiting time: %f\n",(float)xy/n);
printf("Average turnaround time: %f\n",(float)xz/n);
    return 0;
}

//FCFS
