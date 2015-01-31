/*
 Semaphore.c

Illustrates the 
implementation of semaphores by means of
system call pipe
*/

#include <stdio.h>		
#include <stdlib.h>

typedef int * semaphore;
semaphore me;		// Mutual Exclusion semaphore

semaphore
make_sem()
{
int *sem;

sem = calloc(2,sizeof(int));
pipe(sem);
return sem;
}

void
WAIT(semaphore s)
{
int junk;

if (read(s[0], &junk, 1) <=0) {   // it blocks if pipe is empty
  fprintf(stderr, "ERROR : wait\n");
   exit(1);
   }
}

void
SIGNAL(semaphore s)
{

if (write(s[1], "x", 1) <=0) {
  fprintf(stderr, "ERROR : signal\n");
   exit(1);
   }
}

void
process(int i)
{
for(;;) {
  WAIT(me); 
  printf("Entering critical region of process %d\n", i);
  sleep(2);
  printf("Exiting critical region of process %d\n",i);
  SIGNAL(me); 
  sleep(1);  
}
}

int
main()
{
int i;

me = make_sem();
SIGNAL(me);    //  initialize to 1 sem me semaphore
SIGNAL(me);
for(i=0; i<4; i++) 
  if(fork() == 0)
    break;
process(i);
exit(0);
}
