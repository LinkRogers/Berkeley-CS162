#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void) {
  pid_t pid = fork();
  int exit;
  if (pid !=0) {
    wait(&exit);
  }
  printf("Hello World\n: %d\n", pid);
  return 0; 
}
