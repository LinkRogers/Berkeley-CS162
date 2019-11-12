#include <stdio.h>                            
#include <sys/types.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>  

int main(int argc, char **argv) {

  int pid, status;
  int newfd;
  int dupfd;
  printf("newfd = %d\n", newfd);
  if ((newfd = open("output_file.txt", O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) {
    exit(1);
  }
  printf("???\n");
  printf("The last digit of pi is...\n");
  //fflush(stdout);
  dup2(newfd, 1);
  printf("five\n");
  //dup2(newfd, 1);
  exit(0);
}
