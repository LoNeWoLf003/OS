#include <stdio.h>

void calculateTimes(int n, int arrivalTime[], int burstTime[], int completionTime[], int waitingTime[], int turnaroundTime[]) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (arrivalTime[i] > currentTime) {
            currentTime = arrivalTime[i];
        }

        completionTime[i] = currentTime + burstTime[i];
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        currentTime = completionTime[i];
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n];
    int burstTime[n];
    int completionTime[n];
    int waitingTime[n];
    int turnaroundTime[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    calculateTimes(n, arrivalTime, burstTime, completionTime, waitingTime, turnaroundTime);

    printf("\nProcess\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",
               i + 1, arrivalTime[i], burstTime[i], completionTime[i], waitingTime[i], turnaroundTime[i]);
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
