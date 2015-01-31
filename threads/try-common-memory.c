#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int myglobal;

void *
thread_function (void *arg)
{
  int *argc = (int *) arg;
	
  int i, j;
  for (i = 0; i < 20; i++) {
    j = myglobal;
    j = j + 1;
    printf (".");
    fflush (stdout);
    if (*argc > 1)		//  with argc = 1  the thread does not sleep
      sleep (1);			//  and is faster than the main thread
    myglobal = j;
  }
  return NULL;
}

int
main (int argc, char ** argv)
{

  pthread_t mythread;
  int i;

  if (pthread_create (&mythread, NULL, thread_function, &argc)) {
    printf ("error creating thread.");
    abort ();
  }

  for (i = 0; i < 20; i++) {
    myglobal = myglobal + 1;
    printf ("o");
    fflush (stdout);
    sleep (1);
  }

  if (pthread_join (mythread, NULL)) {
    printf ("error joining thread.");
    abort ();
  }

  printf ("\nmyglobal equals %d\n", myglobal);

  exit (0);

}
