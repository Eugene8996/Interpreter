#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *lsh_read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0; // getline сама выделит память
	if (getline(&line, &bufsize, stdin) == -1)
		printf("Getline error\n");
	return line;
}

/*
#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void)
{
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  //int c;
  char c;

  if (!buffer) {
    fprintf(stderr, "lsh: ошибка выделения памяти\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Читаем символ
    //c = getchar();
    scanf("%c", &c);

    //if (c == '\n')


    // При встрече с EOF заменяем его нуль-терминатором и возвращаем буфер
    if (c == EOF || c == '\n') {
    	buffer[position] = '\0';
    	return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // Если мы превысили буфер, перераспределяем блок памяти
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}*/