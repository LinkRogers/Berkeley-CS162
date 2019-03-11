#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void) {
  char** argv = (char**) malloc(3*sizeof(char*));
  argv[0] = "ls";
  argv[1] = ".";
  argv[2] = NULL;
  int i;
  for (i = 0;i < 10;i++) {
    printf("%d\n", i);
    if (i == 3)
      execv("/bin/ls", argv);
  }
}
