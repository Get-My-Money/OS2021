#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char command[150];
	char parameter[150];
	printf("Write your command and parameter: \n");
	
	printf("$ ");
	scanf("%s", command);
	scanf("%s", parameter);
	int PID = fork();

	if(PID > 0){
		char* const arguments[] = {command, parameter, 0};
    char *o[] = {0};
		execve(command, arguments, o);
		printf("\n");
	}
	return 0;
}