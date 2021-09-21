#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N 12


int buffer[N];
int c = 0;
bool ProdAsleep = 0;
bool ConsAsleep = 0;


void *produce(void *argument)
{
	
	int i = 0;
	while (1){
        i++;
		if(i > 12){
			i = 1;
		}

        if (c == N) {
 		    ProdAsleep = 1;
			while(ProdAsleep){
				 sleep(4);
			    }
        	}

        buffer[c] = i;
        c++;

        if (c == 1) 
           	ConsAsleep = 0;

      printf("Producer number: %d\n",buffer[c-1]);
  	}
}



void *consume(void *argument)
{
	int i;
	while (1) {

	    if (c == 0) {
	        ConsAsleep = 1;
			while(ConsAsleep){
				sleep(4);
			    }
	        }
	
	    c--;
		i = buffer[c];
	
	    if (c == N - 1) 
	       ProdAsleep = 0;

      printf("Consumed number: %d\n",buffer[c]);
   	 }
}

int main()
{

	pthread_t producer, consumer;
	int c1 = pthread_create(&producer, NULL, produce, NULL);
	int c2 = pthread_create(&consumer, NULL, consume, NULL);
	
	if (c1)
		printf("Error during creating producer thread");
	if (c2) 
		printf("Error during creating producer thread");

	while(1){}
	
	return 0;

}