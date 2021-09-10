#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	char word[200];
	char* parameters[100];
	printf("Write your command and parameters: \n");
	
	while (1){
		printf("$ ");
		fgets(word, 200, stdin);
		for(int i = 0; i < 100; i++)
			parameters[i] = NULL;
		parameters[0] = (char*)malloc(100);
		int c1 = 0, c2 = 0, i = 0;
	
		while (word[i] != '\n'){
			if (word[i] != ' '){
				parameters[c1][c2] = word[i];
				c2++;
			}
			else{
				parameters[c1][c2] = '\0';
				c1++;
				parameters[c1] = (char*)malloc(100);
				c2 = 0;
				}
			i++;	
			}

		int PID = fork();
		if (PID == 0){
		char *envs[] = {"/bin", (char*)0};
		execve(parameters[0], parameters, envs);
		}
	}
	return 0;
}