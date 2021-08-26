#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])

{
	int n;

	n = atoi(argv[1]);

	puts(argv[1]);


	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < n - i; j++)
			printf(" ");
		for (int j = 0; j < 2 * (i - 1) + 1; j++)
			printf("*");
		for (int j = 0; j < n - i; j++)
			printf(" ");
		printf("\n");
	}

	return 0;
}