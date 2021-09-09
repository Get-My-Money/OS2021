#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  printf("Write your command: \n");
  char command[150];

  while (1) {
    printf("$ ");
    scanf("%s", command);
    system(command);
    printf("\n");
  }
  return 0;
}