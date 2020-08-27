#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "launch.h"

int launch(char **args);
int quit(char **args);

char *builtin_str[] = {
  "quit"
};

int (*builtin_func[]) (char **) = {
  &quit
};

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Дочерний процесс
    if (execvp(args[0], args) == -1) {
      perror("launch");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Ошибка при форкинге
    perror("launch");
  } else {
    // Родительский процесс
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // Была введена пустая команда.
    return 1;
  }

  for (i = 0; i < num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return launch(args);
}

int quit(char **args)
{
  return 0;
}