#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *line;
	char **args;
	int status;

	printf("Enter the command\n");
	printf("Help to see commands\n");

	do {
		printf("> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);
}