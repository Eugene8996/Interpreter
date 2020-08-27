#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"



char **split_line(char *line)
{
  	int bufsize = LSH_TOK_BUFSIZE, position = 0;
  	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

  	if (!tokens) {
		fprintf(stderr, "split_line: ошибка выделения памяти\n");
		exit(EXIT_FAILURE);
  	}

  	token = strtok(line, LSH_TOK_DELIM);
  	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
		  	bufsize += LSH_TOK_BUFSIZE;
		  	tokens = realloc(tokens, bufsize * sizeof(char*));
		  	if (!tokens) {
				fprintf(stderr, "split_line: ошибка выделения памяти\n");
				exit(EXIT_FAILURE);
		  	}
		}
		token = strtok(NULL, LSH_TOK_DELIM);
  	}
  	tokens[position] = NULL;
  	return tokens;
}