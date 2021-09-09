#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	int n = 48;
	int PID = fork();

	if (PID == 0) {
		printf("Hello from Child[%d-%d]\n", PID, n);
	}
  else
		printf("Hello from Parent[%d-%d]\n", PID, n);

	return 0;
}