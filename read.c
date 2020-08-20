#include <stdio.h>
#include <string.h>

char *lsh_read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0; // getline сама выделит память
	getline(&line, &bufsize, stdin);
	return line;
}