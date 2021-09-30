#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    int *arr = malloc(N*sizeof(int));

    for (int i = 0; i < N; i++)
        arr[i] = i;

    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}