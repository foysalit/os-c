#include <stdio.h>
#include <cstdlib>
#include <unistd.h>

int main() {
	printf("I'm the parent, my PID is %d, my parent is process %d\n",
	           getpid(), getppid());

	int forkReturned = fork();

	/*
	                           p = fork();
							assume no errors 
							you now have two 
							programs running 
                         --------------------
      if (p > 0) {                |            if (p == 0) {
        printf("parent\n");       |              printf("child\n");
        ...                       |              ...
	*/
	printf("the value of fork() is %d\n", forkReturned);

	if (forkReturned == 0){
		// branch is for the parent
		sleep (25);
	}
	printf("This sentence has been printed by process: %d my parent is process %d\n",
	        getpid(), getppid());

	// who is process number 1 ?? 

	exit(43);  // return 0;
}
