#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()

{
	puts("Enter some text: ");
	char arr[256];
	fgets(arr, 256, stdin);

	int a = strlen(arr);

	for (int i = 0; i < a; i++) {
		putchar(arr[a - 1 - i]);
	}



	return 0;
}