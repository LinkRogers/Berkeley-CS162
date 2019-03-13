#include <stdio.h>                            
#include <sys/types.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>  
#include <errno.h>

int main(int argc, char **argv) {

  int pid, status;
  int newfd;
  int dupfd;
  char *cmd[] = { "/bin/ls", "-al", "/", 0 };
  if ((pid = fork()) < 0) {
    perror("fork() failed!");
    exit(1);
  }
  if (argc != 2) {
    fprintf(stderr, "usage: %s output_file\n", argv[0]);
    exit(1);
  }
  if ((newfd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) {
    perror(argv[1]); /* open failed */
    exit(1);
  }
  printf("writing output of the command %s to \"%s\"\n", cmd[0], argv[1]);
  dup2(newfd, 1);
  execvp(cmd[0], cmd);
  perror(cmd[0]); /* execvp failed */
  close(newfd);
  printf("all done");
  exit(1);
}
