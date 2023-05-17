#include <stdio.h>

#define MAX_PARTITIONS 5

void firstFit(int partitions[], int n, int processes[], int m) {
    int allocation[m];
	int i,j;
    for (i = 0; i < m; i++)
        allocation[i] = -1;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }

    printf("Process Size\tPartition Index\n");
    for ( i = 0; i < m; i++) {
        printf("%d KB\t\t", processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int partitions[MAX_PARTITIONS] = {40, 10, 30, 60};
    int processes[] = {100, 50, 30, 120, 35};
    int numPartitions = sizeof(partitions) / sizeof(partitions[0]);
    int numProcesses = sizeof(processes) / sizeof(processes[0]);

    printf("First-Fit Algorithm:\n");
    firstFit(partitions, numPartitions, processes, numProcesses);

    return 0;
}

