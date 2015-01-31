#include <stdio.h>
#include <cstdlib>
#include <unistd.h>


int x,y; // global variables are not shared 
int main() { 
	int x,y; 

	x = 4;
	if (fork()){		// recall 0 in C is FALSE
		y = 5;  	 // parent != 0
		x = 15;
		sleep(5);
	} else {
		y= -5;	// child
	}

	printf(" x = %d y = %d process %d, PPID %d\n",
	          x, y, getpid(), getppid());

	exit(0);
}
