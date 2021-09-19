#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
bool T = 0;

void* ThreadFunc(void* v)
{
    int *k = (int*) v;
    while(!T){}
    printf("Hello from thread № %d \n", *k);
    T = 0;
    pthread_exit(NULL);
}



int main()
{
    int N = 5;
    pthread_t ids[N];

    for(int i = 0; i < N; i++){
        printf("Creating thread № %d\n", i);
        pthread_create(&ids[i], NULL, ThreadFunc, (void*)&i);
        T = 1;
        pthread_join(ids[i], NULL);
        printf("Termination of thread № %d \n", i);
        printf("\n");
        while(T){ printf("fm");}
	    }
    return 0;
}