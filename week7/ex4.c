#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


void *real_realloc(void *arr, size_t new_size) {

    if (new_size == 0) {
        free(arr);
        return NULL;
    } else if (sizeof(arr) == 0) {
        return malloc(new_size);
    } else {
        void *new_array = malloc(new_size);
        memcpy(new_array, arr, new_size);
        free(arr);
        return new_array;
    }
}


int main(){
	srand(time(NULL));

	int n1 = 0, n2 = 4;
  printf("First case:\n");
  int* a1 = malloc(n1* sizeof(int));
	for(int i = 0; i < n1; i++){
		a1[i] = 11;
		printf("%d ",a1[i]);
	}
  printf("\n");
	a1 = real_realloc(a1, n2*sizeof(int));
	for(int i  = 0; i < n2-n1; i++){
		a1[n1+i] = 2;
	}
	for(int i = 0; i < n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");


  n1 = 4, n2 = 0;
  printf("Second case:\n");
  a1 = malloc(n1* sizeof(int));
	for(int i = 0; i < n1; i++){
		a1[i] = 11;
		printf("%d ",a1[i]);
	}
  printf("\n");
	a1 = real_realloc(a1, n2*sizeof(int));
	for(int i  = 0; i < n2-n1; i++){
		a1[n1+i] = 2;
	}
	for(int i = 0; i < n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");


  n1 = 3, n2 = 7;
  printf("Third case:\n");
  a1 = malloc(n1* sizeof(int));
	for(int i = 0; i < n1; i++){
		a1[i] = 11;
		printf("%d ",a1[i]);
	}
  printf("\n");
	a1 = real_realloc(a1, n2*sizeof(int));
	for(int i  = 0; i < n2-n1; i++){
		a1[n1+i] = 2;
	}
	for(int i = 0; i < n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");


  n1 = 7, n2 = 3;
  printf("Fourth case:\n");
  a1 = malloc(n1* sizeof(int));
	for(int i = 0; i < n1; i++){
		a1[i] = 11;
		printf("%d ",a1[i]);
	}
  printf("\n");
	a1 = real_realloc(a1, n2*sizeof(int));
	for(int i  = 0; i < n2-n1; i++){
		a1[n1+i] = 2;
	}
	for(int i = 0; i < n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");

	return 0;
}