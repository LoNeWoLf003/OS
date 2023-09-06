#include <stdio.h>

void findWaitingTime(int n, int burstTime[], int remainingTime[], int waitingTime[]) {
    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int shortestJob = -1;
        int shortestTime = 9999;

        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0 && remainingTime[i] < shortestTime && currentTime >= i) {
                shortestJob = i;
                shortestTime = remainingTime[i];
            }
        }

        if (shortestJob == -1) {
            currentTime++;
        } else {
            remainingTime[shortestJob]--;

            if (remainingTime[shortestJob] == 0) {
                completed++;
                waitingTime[shortestJob] = currentTime - burstTime[shortestJob];
            }

            currentTime++;
        }
    }
}

void findTurnaroundTime(int n, int burstTime[], int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n];
    int remainingTime[n];
    int waitingTime[n];
    int turnaroundTime[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }

    findWaitingTime(n, burstTime, remainingTime, waitingTime);
    findTurnaroundTime(n, burstTime, waitingTime, turnaroundTime);

    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
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
