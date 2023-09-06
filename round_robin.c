#include <stdio.h>

#define MAX_PROCESSES 50

void calculateTimes(int n, int burstTime[], int timeQuantum, int completionTime[], int waitingTime[], int turnaroundTime[]) {
    int remainingTime[MAX_PROCESSES];
    int currentTime = 0;
    int completed = 0;

    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] <= timeQuantum) {
                    currentTime += remainingTime[i];
                    completionTime[i] = currentTime;
                    remainingTime[i] = 0;
                    completed++;
                } else {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }
}

int main() {
    int n, timeQuantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[MAX_PROCESSES];
    int completionTime[MAX_PROCESSES];
    int waitingTime[MAX_PROCESSES];
    int turnaroundTime[MAX_PROCESSES];

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    calculateTimes(n, burstTime, timeQuantum, completionTime, waitingTime, turnaroundTime);

    printf("\nProcess\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\n",
               i + 1, burstTime[i], completionTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Calculate and display average waiting time and average turnaround time
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
