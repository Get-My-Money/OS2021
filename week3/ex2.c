# include <stdio.h>
# include <stdlib.h>
#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0]))


void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}


void bubble_sort(int arr[], int arr_len){
   for (int i = 0; i < arr_len - 1; i++)         
       for (int j = 0; j < arr_len - i - 1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}


int main()
{
    int arr[] = {37, 17, 85, 47, 12, 98, 16};

    int n = ARR_SIZE(arr);
    printf(" ");
    printf("Initial array:\n");
    printf(" ");
    for (int i=0; i < n; i++)
        printf("%d\n ", arr[i]);

    bubble_sort(arr, n);
    printf("Array after bubbleSort:\n");
    printf(" ");
    for (int i=0; i < n; i++)
      printf("%d\n ", arr[i]);

    return 0;
}