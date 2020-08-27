#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;
	if (getline(&line, &bufsize, stdin) == -1)
		printf("Getline error\n");
	return line;
}