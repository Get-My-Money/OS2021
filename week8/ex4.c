#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>
#include <sys/resource.h>

int main()
{
	int size = 10485760;

	for (int i = 0; i < 10; i++) {
		  char *p = (char*) malloc(size);
		  memset(p, 0, size);
	
		  struct rusage us;
		  int err = getrusage(RUSAGE_SELF, &us);
    	printf("Memory usage: %ld\n", us.ru_maxrss);
	
		  sleep(1);
	}
}