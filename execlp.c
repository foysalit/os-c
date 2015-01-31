/*

execlp.c

Illustrates the use of system calls system and exec

l in exec is for list: the arguments are passed in a list
p in exec is for PATH: the executable file is searched in the directories listed in PATH

The second argument of exec is the name of the process during its running phase,
it corresponds to argv[0].

*/
#include <stdio.h>
#include <unistd.h>

int
main (int argc, char ** argv)
{
  int pid;

  system ("date");	

// system ("date") creates a shell process that execute
// command "date" - output goes to screen
// return here

  if (execlp ("argv", "myls", "-l", "-R", "/cygdrive/d", (char *) 0) < 0)
    printf ("error exec\n");
  printf ("listing complete !!!\n");	// NEVER REACHED
  exit (0);
}
