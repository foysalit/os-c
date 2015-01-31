// If argc > 1 
//   wait for the end of all its offsprings
// else
//     wait for the end of any offspring

#include <signal.h>

int
main (int argc, char ** argv) {

int i, ret, code;

if (argc > 1)
 signal(SIGCHLD, SIG_IGN);  // ignores the childtermination 

for(i=1;i<6;i++)
  if (fork() == 0) {   		// child
    sleep (5*i);
    printf ("Child %d slept%d seconds\n", getpid(), i*5);
    exit(i);  		   // exit with code i
  }

sleep (15);		// allows some childs to terminate
    
ret = wait(&code);

printf("Wait: ret = %d code = %x\n", ret, code);

}
