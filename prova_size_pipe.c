// verify the size of a pipe

#include <stdio.h>

int fd[2];

int
main(int argc,  char ** argv)
{

char buf[256];

int n = 0;
char c = '1';

pipe(fd);

setbuf(stdout,0); // no buffering

if (fork()){
  for (;;) {
     write(fd[1], &c, 1);
     printf("%d\r", ++n);
   }
}
else{
    sleep(10);
    read(fd[0],buf,6);
}
}
