#include <stdlib.h>
#include <stdio.h>


int main() {
    int c;
    printf("Enter total number of processes(maximum 10): ");
    scanf("%d", &c);
    
    int *arr = malloc(c*4);
    int *ser = malloc(c*4); 
    int *sta= malloc(c*4);
    
    for (int i = 0; i < c; i++) {
        printf("Enter the arrival time for process №%d: ", i+1);
        scanf("%d", arr+i);
        printf("Enter the burst time for process №%d: ", i+1);
        scanf("%d", ser+i);
    }
    
    int t1, t2;
    for (int i = c - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                t1 = arr[j];
                t2 = ser[j];
                arr[j] = arr[j+1];
                ser[j] = ser[j+1];
                arr[j+1] = t1;
                ser[j+1] = t2;
            }
        }
    }
    
    
    for (int i = 0; i < c; i++) {
        sta[i] = arr[i];
        if (i > 0 && sta[i-1] + ser[i-1] > sta[i]) {
            sta[i] = sta[i-1] + ser[i-1];
        }
    }
    
    float ATT = 0;
    float AWT = 0;
    printf("P#\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n\n");
    for (int i = 0; i < c; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arr[i], ser[i],sta[i] + ser[i], sta[i] + ser[i] - arr[i], sta[i] - arr[i]);
        ATT += sta[i] + ser[i] - arr[i];
        AWT  += sta[i] - arr[i];
    }
    printf("\n");
    printf("Average Turnaround Time: %f\n", ATT/c);
    printf("Average WT: %f\n", AWT/c);
    return 0;
}