#include <stdio.h>
#include <sys/types.h>

int main(void) {
  int stuff = 7; 
  int count;
  pid_t pid = fork(); 
  printf("Stuff is %d\n", stuff);
  if (pid == 0)
    stuff = 6; 
}
