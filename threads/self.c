/*    self.c Shows that a process is a a single thread */

#include <stdio.h>
#include "pthread.h"		// POSIX threads


int
main (void)
{
  pthread_t pt;
 
  pt = pthread_self();

  printf("main thread id = %ld\n", pt);
  printf("process     id = %d\n",  getpid());
}
