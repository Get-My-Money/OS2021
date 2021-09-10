#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	char command[100];
	char parameters[100];
	char word[200];
	printf("Write your command and parameter: \n");

	while (1) {
		printf("$ ");
		fgets(word, 200, stdin);
		int s = 0;

		while (word[s] != ' ') {
			command[s] = word[s];
			s++;
		}

		while (word[s] != '\n') {
			parameters[s - strlen(command)] = word[s + 1];
			s++;
		}

		int PID = fork();
		if (PID > 0) {
			char* const arguments[] = { command, parameters, 0 };
			char *env[] = { 0 };
			execve(command, arguments, env);
		}

	}
	return 0;
}