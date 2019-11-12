#include <stdio.h>                            
#include <sys/types.h> 
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>  

void sigint_handler(int sig)
{
  char c;
  printf("Ouch, you just hit Ctrl-C?. Do you really want to quit [y/n]?");
  c = getchar();
  if (c == 'y' || c == 'Y')
  {
    printf("now we are exiting !!!!!!!!!!!!!!!!!!\n");
    exit(0);
  }
  else 
  {
    printf("c entered = %c\n", c);
    printf("Not y or Y");
  }
}

int main() {
  signal(SIGINT, sigint_handler);
  printf("in main\n");
  while(1);
}
