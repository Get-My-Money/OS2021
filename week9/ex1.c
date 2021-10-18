#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>


void Simulator(int num){
    int hits = 0;
    int ur = 0;
    int misses = 0;
    int ln = 2;
    int ir = 2;
    int fr = num; 
    int *re = malloc(fr * 4);
    int *hm = malloc(fr * 4);
    int ob = 1;
    int pn;
    for (int i = 0; i < fr; i++){
      re[i] = 0;
      hm[i] = 0;
    }
    FILE *input;
    input = fopen("input.txt", "r");

    while (fscanf(input, "%d", &pn) != EOF) {
        int ht = 0;
        for (int i = 0; i < fr; i++) {
            if (pn == re[i]) {
                hm[i] = 128 + hm[i]/2;
                ur++;
                if (hits+1 % ln == ur){
                    ln -= 1;
                    ht = 1;
                    misses -= 1;
                    hits += 2;
                    ur--;
                }
                else {
                    ln++;
                    ht = 1;
                    hits++;
                }
                break;
            }
        }

        if (ht == 0) {
            int min = 0;
            for (int i = 0; i < fr; i++) {
                if (hm[i] < hm[min])
                    min = i;
            }

            ir++;
            re[min] = pn;
            hm[min] = 128;
            if (misses+1 % ir == ob && (fr/(hits+re[0]) == 1)){
                misses--;
                hits += 2;
                ob -= 2;
            }
            else{
                misses++;
                ob++;
            }
        }
    }

    fclose(input);
    printf("Number of hits: %d\n", hits);
    printf("Number of misses: %d\n", misses);
    printf("Hit/Miss ratio: %lf\n", (double) hits/(double) misses);
}






int main() {

Simulator(10);
printf("\n");
Simulator(50);
printf("\n");
Simulator(100);

return 0;   
}