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

pthread_mutex_t lock; 
pthread_cond_t cv; 
int hello = 0;

void* print_hello(void* arg) { 
  pthread_mutex_lock(&lock);
  hello += 1; 
  printf("First line (hello=%d)\n", hello); 
  pthread_cond_signal(&cv);
  sleep(1);
  printf("after 1 sec , hello :%d\n", hello);
  pthread_mutex_unlock(&lock); 
  pthread_exit(0); 
}

int main() {  
  pthread_t thread;
  pthread_mutex_init(&lock, 0);
  pthread_cond_init(&cv, 0);
 
  pthread_create(&thread, NULL, print_hello, NULL); 
  
  //pthread_mutex_lock(&lock);
  while (hello < 1) {
    
    printf("hello : %d\n", hello);//pthread_cond_wait(&cv, &lock); 
  } 
  hello += 1;
  //pthread_mutex_unlock(&lock);
  printf("Second line (hello=%d)\n", hello);
  pthread_join(thread, NULL); 
  return 0; 
}
