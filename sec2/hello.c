#include <stdio.h>
#include <sys/types.h>

int main() { 
  pid_t pid = fork();
  printf("hi\n"); 
  printf("Hello World: %d\n", pid); 
}

