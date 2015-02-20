#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int i;

  for (i=0; i<2 && !fork(); i++){
    int f = fork();
    if (f)
      system("echo i+$i");

    printf("i: %d fork(): %d self: %d parent: %d \n", i, f, getpid(), getppid());
    execlp("echo","system", "i++", (char *)0);
  }
}