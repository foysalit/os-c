/*
fork2. c
Illustrates fork, wait and exit return information

Use:  Prompt> fork2
      echo $?
Last shell command should print the parent return value (15)

*/

#include <stdio.h>

main() {
int n, status, cpid;

  printf("Parent pid = %d\n",  getpid());

  n = fork();

  if (n != 0) {
//  parent code
     printf ("I'm the parent with PID %d \t fork returned %d \t my parent is %d\n",
              getpid(), n, getppid());
     status = 0;
     sleep(5);		// verify status of child
     cpid = wait(&status);
     printf("I received from my child %d this information %x\n", 
             cpid, status);
   }
   else {		// child code
        printf ("I'm the child with PID %d \t fork returned %d \t my parent is %d\n",
	           getpid(), n, getppid());
	      sleep(20);
        printf("Child complete\n");
        status=123;
	      exit(4);
     }
     printf("Parent complete\n");
     exit(15);
}
