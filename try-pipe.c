/*
try-pipe.c

Illustrates the use of shell pipes

Example: ls | try-pipe 
*/

#include <stdio.h>
#include <stdlib.h>

int
main ()
{

char buf[1024];

while(gets(buf)) {
  printf("HELLO ");
  puts(buf);
 
}

}
