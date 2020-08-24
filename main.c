#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "read.c"
//#include "pars.c"

char *lsh_read_line(void);
char **lsh_split_line(char *line);

int main()
{
	char *line;
	char **args;
	int status = 0;
	int i = 0;
	char c;

	printf("Enter the command\n");
	printf("Help to see commands\n");

	do {
		printf("> ");
		line = lsh_read_line();
		printf("%s", line);
		args = lsh_split_line(line);
		//status = lsh_execute(args);
		
		i = 0;
		//args[i] = NULL;
		scanf("%d", &status);
		//status = getchar();
		while ((c = getchar()) != '\n' && c != EOF);
		free(line);
		//free(args);
	} while (status);
}