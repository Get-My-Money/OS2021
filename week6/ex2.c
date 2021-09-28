#include <stdio.h>
#include <stdlib.h>



int main() 
{
  int c;
  printf("Enter total number of processes(maximum 10): ");
  scanf("%d", &c);
  int *arr = malloc(c*4);
  int *bur = malloc((c+1)*4); 
  int *temp = malloc(c*4);
  int s, count = 0, time, end;
  float AWT, ATT;


  for (int i = 0; i < c; i++) {
      printf("Enter the arrival time for process №%d: ", i+1);
      scanf("%d", arr+i);
      printf("Enter the burst time for process №%d: ", i+1);
      scanf("%d", bur+i);
      temp[i] = bur[i];
    }

  
  bur[c] = 9999; 
  printf("P#\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n\n");
  for(time = 0; count != c; time++)
    {
      s = c;
      for(int i = 0; i < c; i++)
      {
          if(arr[i] <= time && bur[i] < bur[s] && bur[i] > 0)
              {
                s = i;
                }
            }
      bur[s]--;
      if(bur[s] == 0)
      {
          count++;
          end = time + 1;
          printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", count, arr[s], temp[s], end, end - arr[s], end - arr[s] - temp[s]);

          AWT += + end - arr[s] - temp[s];
          ATT += end - arr[s];
            }
      }
    printf("\n");
    printf("Average Turnaround Time: %f\n", ATT/c);
    printf("Average WT: %f\n", AWT/c); 
    return 0;
}










