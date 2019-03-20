#include <stdio.h>                            
#include <sys/types.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>  
#include <errno.h>
#include <pthread.h>

void* identify(void* arg) {
  pid_t pid = getpid();
  printf("my pid is %d\n", pid);
  return NULL;
}

int main(int argc, char **argv) {
  pthread_t thread;
  pthread_create(&thread, NULL, &identify, NULL);
  identify(NULL);
  return 0;
}
