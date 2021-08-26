#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void change(int *a, int *b) {

	int p1;
	int p2;

	p1 = *a;
	p2 = *b;
	*a = p2;
	*b = p1;

}


int main()
{
	int a;
	int b;
	int c = 0;
	char arr1[100];
	char arr2[100];


	puts("Enter 2 integer numbers in 1 row: ");
	char arr[256];
	fgets(arr, 256, stdin);

	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == ' ')
			c = i;
		if (c == 0)
			arr1[i] = arr[i];
		else
			arr2[i - c] = arr[i + 1];
	}

	a = atoi(arr1);
	b = atoi(arr2);

	change(&a, &b);

	puts("Number 1: ");
	printf("%d\n", a);
	puts("Number 2: ");
	printf("%d\n", b);



	return 0;
}