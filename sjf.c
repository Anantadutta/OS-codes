2.SJF
#include <stdio.h>

int main() {
    int n, i, j, temp;
    float avg_wt, avg_tat;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n];
    
    printf("Enter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]); // Stores burst time
    }
    
    // Sorting burst time in ascending order using selection sort
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[j] < bt[i]) {
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    
    // Waiting time for first process will be zero
    wt[0] = 0;
    
    // Calculate waiting time and turnaround time
    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++)
            wt[i] += bt[j];
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }
    
    avg_wt = total_wt / n;
    avg_tat = total_tat / n;
    
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    
    return 0;
}
