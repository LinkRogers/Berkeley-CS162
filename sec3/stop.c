#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
  signal(SIGINT, SIG_IGN);
  while(1);
}
