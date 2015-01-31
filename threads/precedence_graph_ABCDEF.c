/* Implements a precedence graph.  */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pthread.h"

  
int random_time(int max){
	return (int)(rand() % max) + 1;
}	

static void *
CF (void *arg)
{
  
  int *t = (int *) arg;
  int rt;
  
  sleep(*t);
  
  printf ( "C after %d seconds\n", *t);
  rt = random_time(2);
  sleep(rt);
  printf ( "F after %d seconds\n", *t);
  return  0;
}

static void *
E (void *arg)
{
  int *t = (int *) arg;
  
  sleep(*t);
  printf ( "E after %d seconds\n", *t);
  return  0;
}
	

int
main (void)
{
  pthread_t th_cf, th_e;
  int *rt;
  void *retval;
   
  srand(getpid());
  rt = (int *) malloc(sizeof(int));
  
  // sleep(random_time(10));
  printf("A\n");
  
    *rt = random_time(10);
    pthread_create (&th_cf, NULL, CF, (void *) rt);
  
  sleep(random_time(5));
  printf("B\n");
  
    *rt = random_time(10);
    pthread_create (&th_e, NULL, E, (void *) rt);
  
  sleep(random_time(5));
  printf("D\n");
  
  pthread_join (th_cf, &retval);
  pthread_join (th_e, &retval);
  sleep(random_time(8));
  printf("G\n");
  
  return 0;
}
