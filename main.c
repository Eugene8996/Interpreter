#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "launch.h"

char *read_line(void);
char **split_line(char *line);
int execute(char **args);


int main()
{
	char *line;
	char **args;
	int status = 1;
	char c;

	printf("Enter the command\n");

	do {
		printf("> ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		//while ((c = getchar()) != '\n' && c != EOF);
		free(line);
		free(args);
	} while (status);
}