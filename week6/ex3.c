#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


int main() {

    int i,c,q;
    float AWT = 0, ATT = 0;

    printf("Enter total number of processes(maximum 10): ");
    scanf("%d", &c);
    printf("Enter quantum: ");
    scanf("%d", &q);

    int bur[c], temp[c], arr[c], tat[c],
    wt[c], ct[c];
    bool ex[c];


    for (i = 0; i < c; i++) {
        printf("Enter the arrival time for process №%d: ", i+1);
        scanf("%d", arr+i);
        printf("Enter the burst time for process №%d: ", i+1);
        scanf("%d", bur+i);
        temp[i] = bur[i];
        ex[i] = false;
    }

    int time = arr[0], end = 0;
    i = 0;
    while (end != c) {
        if (ex[i] == true) {
            i = (i + 1)%c;
            continue;
        }

        if (bur[i] <= q) {
            time += bur[i];
            ct[i] = time; 

            tat[i] = ct[i] - arr[i]; 
            ATT += tat[i];

            if (tat[i] - temp[i] > 0)
                wt[i] = tat[i] - temp[i];
            else
                wt[i] = 0;
            AWT += wt[i];
            end++;
            ex[i] = true;
            i = (i + 1)%c;
        } else {

            time += q;
            bur[i] -= q;
            i = (i + 1)%c;
        }
    }

    printf("P#\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n\n");
    for (i = 0; i < c; i++)
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arr[i], bur[i], arr[i] + bur[i] + wt[i], tat[i], wt[i]);

    printf("\n");
    printf("Average Turnaround Time: %f\n", ATT/c);
    printf("Average WT: %f\n", AWT/c); 
    return 0;
}
