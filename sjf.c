#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortArrivalBurstTime(int n, int arrivalTime[], int burstTime[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrivalTime[j] > arrivalTime[j + 1]) {
                swap(&arrivalTime[j], &arrivalTime[j + 1]);
                swap(&burstTime[j], &burstTime[j + 1]);
            }
        }
    }
}

void calculateTimes(int n, int arrivalTime[], int burstTime[], int completionTime[], int waitingTime[], int turnaroundTime[]) {
    int currentTime = 0;
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    int completed = 0;

    while (completed < n) {
        int shortestJob = -1;
        int shortestTime = 9999;

        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingTime[i] < shortestTime && remainingTime[i] > 0) {
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
                completionTime[shortestJob] = currentTime + 1;
                turnaroundTime[shortestJob] = completionTime[shortestJob] - arrivalTime[shortestJob];
                waitingTime[shortestJob] = turnaroundTime[shortestJob] - burstTime[shortestJob];
            }

            currentTime++;
        }
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

    sortArrivalBurstTime(n, arrivalTime, burstTime);
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
