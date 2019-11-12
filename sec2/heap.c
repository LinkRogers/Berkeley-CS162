#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void) {
  int* stuff = malloc(sizeof(int)*1); 
  *stuff = 7;
  pid_t pid = fork(); 
  printf("Stuff is %d\n", *stuff);
  if (pid == 0)
    *stuff = 6;
  printf("Later stuff is %d\n", *stuff);

  return 0; 
}
