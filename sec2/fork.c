#include <stdio.h>
#include <sys/types.h>

int main(void) {
  int i; 
  int count = 1;
  for (i = 0; i < 3; i++) {  
    pid_t pid = fork(); 
    printf("a process!%d, i = %d\n",count,i);
    count+=1; 
  } 
}
