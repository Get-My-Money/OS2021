#include <pthread.h>
#include <unistd.h>
#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N 12


int buffer[N];
int c = 0;
bool ProdAsleep = 0;
bool ConsAsleep = 0;


void *produce(void *argument) {
	
	int i = 0;
	while (1){
        i++;

    if (c == N) {
 		ProdAsleep = 1;
		while(ProdAsleep){
			sleep(5);
			}
        }

    buffer[c] = i;
    c++;

    if (c == 1) {
        ConsAsleep = 0;
        }

	printf("There is producer working\n");
	sleep(60);
	
  	}
}


void *consume(void *argument)
{
	int i;
	while (1) {
    if (c == 0) {
	    ConsAsleep = 1;
		    while(ConsAsleep){
				sleep(5);
			}
	    }
	
	 c--;
	 i = buffer[c];
	
	 if (c + 1 == N) {
	     ConsAsleep = 0;
        }
    }
}




int main()
{
	pthread_t producer, consumer;
	pthread_create(&producer, NULL, produce, NULL);
	pthread_create(&consumer, NULL, consume, NULL);
	
	while(1){
		fflush(stdout);
	}
	
	return 0;
}