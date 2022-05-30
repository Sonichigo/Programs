#include <stdio.h>
#include <stdlib.h>

void main(){
    int n, m, bt[10][10], i, j, count=0, minID, minBurst, maximum, makespan = 0;
    int *machineID, *machineBurst, *completed, *completionTime;

    printf("Enter number of TASKS: ");
    scanf("%d",&n);
    printf("Enter number of MACHINES: ");
    scanf("%d",&m);
    for(i=0;i<m;i++){
        printf("Enter execution time for machine %d: ",(i+1));
        for(j=0;j<n;j++)
            scanf("%d",&bt[i][j]);
    }
    machineID = (int*) calloc(n,(sizeof(int)));
    machineBurst = (int*) calloc(n,(sizeof(int)));
    completed = (int*) calloc(n,(sizeof(int)));
    completionTime = (int*) calloc(m,(sizeof(int)));

    while(count < n){
        for(i=0;i<n;i++){
            minID = 0;
            minBurst = bt[0][i];
            for(j=0;j<m;j++){
                if(bt[minID][i] > bt[j][i]){
                    minID = j;
                    minBurst = bt[minID][i];
                }
            }
            machineID[i] = minID;
            machineBurst[i] = minBurst;
        }

        maximum = 0;
        for(i=1;i<n;i++){
            if(!completed[i] && (machineBurst[i] > machineBurst[maximum]))
                maximum = i;
        }
        printf("The task %d will be assigned to machine %d.\n",(maximum+1),(machineID[maximum]+1));
        completionTime[machineID[maximum]] = machineBurst[maximum];
        completed[maximum] = 1;
        for(i=0;i<m;i++)
            bt[i][maximum] = 0;
        for(i=0;i<n;i++)
            bt[machineID[maximum]][i] += machineBurst[maximum];
        count++;
    }
    for(i=0;i<m;i++){
        if(completionTime[i] > makespan)
            makespan = completionTime[i];
    }
    printf("Total completion time: %d",makespan);
}