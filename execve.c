/*

execve.c

Illustrates the use of system calls system and exec

v in exec is for variables: the arguments are passed as a sequence of variables
e in exec is for env: the executable file inherits the shell environment variables

*/
// Use of system calls system and exec
// use: execve command arg environment

#include <stdio.h>
#include <unistd.h>

int
main (int argc, char **argv, char ** envp)
{
  int pid;

  char * arguments[10]={"name", "-l", "-R", "/", "\0"};

//  strcpy(arguments[0] , "name");

  printf("%s\n", envp[0]);
  system ("date");	

// system ("date") creates a shell process that execute
// command "date" - output goes to screen
// return here

// if (execlp ("argv", "name", "-l", "-R", "/" (char *) 0) < 0)
  if (execve ("argv", arguments , envp) < 0) {  // Notice complete path
    printf ("error exec\n");
    exit(1);
  }
  printf ("listing complete !!!\n");	// NEVER REACHED
  exit (0);
}
