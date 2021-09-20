#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* ThreadFunc(void* v)
{
    int *k = (int*) v;
    printf("Hello from thread № %d \n", *k);
    pthread_exit(NULL);
}

int main()
{
    int N = 5;
    pthread_t ids[N];

    for(int i = 0; i < N; i++){
        printf("Creating thread № %d\n", i);
        pthread_create(&ids[i], NULL, ThreadFunc, (void*)&i);
        printf("Termination of thread № %d \n", i);
        printf("\n");
	    }
    return 0;
}