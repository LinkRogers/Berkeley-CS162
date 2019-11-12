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
#include <string.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

int n = 3;

void* counter(void* arg) { 
  pthread_mutex_lock(&lock);
  printf("counter got the lock\n"); 
  for (n = 3; n > 1; n--) 
    printf("%d\n", n); 
  pthread_cond_signal(&cv); 
  pthread_mutex_unlock(&lock); 
}

void* announcer(void* arg) { 
  pthread_mutex_lock(&lock); 
  while (n != 0) {
    printf("in announcer, n = :%d\n", n); 
    printf("in announcer, got lock, n = %d\n", n);
    pthread_cond_wait(&cv, &lock); 
    printf("in annouce, return from wait, n = %d\n", n);
  }
  pthread_mutex_unlock(&lock); 
  printf("FALCON HEAVY TOUCH DOWN!\n"); 
}

int main() { 
  pthread_t t1, t2; 
  pthread_create(&t1, NULL, counter, NULL);
  pthread_create(&t2, NULL, announcer, NULL);
  pthread_join(t1, NULL); 
  pthread_join(t2, NULL); 
  return 0; 
}
