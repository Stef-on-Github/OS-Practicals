#include<stdio.h>

int main() {
    int bt[10]={0}, at[10]={0}, tat[10]={0}, wt[10]={0}, ct[10]={0}, p[10];
    int n, sum=0, i, j, temp=0;
    float totalTAT=0, totalWT=0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter %d processes: ", n);
    for(i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter arrival time and burst time for each process\n\n");

    for(int i=0; i<n; i++) {
        printf("Arrival time of process[%d]: ", i+1);
        scanf("%d", &at[i]);
        
        printf("Burst time of process[%d]: ", i+1);
        scanf("%d", &bt[i]);
        
        printf("\n");
    }
    
    // Sorting based on arrival time and process ID
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(at[i] == at[j]) { // If arrival times are equal, prioritize by process ID
                if(p[i] < p[j]) {
                    temp=at[i];
                    at[i]=at[j];
                    at[j]=temp;
                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
            else if(at[i] < at[j]) { // Otherwise, sort by arrival time
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    // Calculate completion time of processes 	
    for(int j=0; j<n; j++) {
        if (j > 0 && ct[j-1] < at[j]) { // If there's idle time between processes
            int idle_duration = at[j] - ct[j-1];
            printf("Idle\t %d\t %d\n", ct[j-1], at[j]);
            for (int k = j; k < n; k++) {
                ct[k] += idle_duration; // Adjust CT for processes after idle time
            }
            sum += idle_duration;
        }
        sum += bt[j];
        ct[j] = sum;
    }

    // Calculate turnaround time and waiting times
    for(int k=0; k<n; k++) {
        tat[k] = ct[k] - at[k];
        totalTAT += tat[k];
        wt[k] = tat[k] - bt[k];
        totalWT += wt[k];
    }

    printf("Solution:\n\n");
    printf("P\t AT\t BT\t CT\t TAT\t WT\t\n\n");
    
    // Displaying in ascending order of processes
    for(int i=0; i<n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
        
    printf("\n\nAverage Turnaround Time = %f\n", totalTAT/n);
    printf("Average WT = %f\n\n", totalWT/n);

    return 0;
}
