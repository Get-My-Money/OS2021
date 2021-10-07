#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zconf.h>


int main()
{
	int size = 1024*1024*10;

	for (int i = 0; i < 10; i++) {
		  char *p = (char*) malloc(size);
		  memset(p, 0, size);
		  sleep(1);
	}
	return 0;
}

//Due to the fact that I work at replit.com, all my swaps are 0