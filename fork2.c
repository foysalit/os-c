#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

/*
fork2. c
Illustrates fork, wait and exit return information

Use:  Prompt> fork2
      echo $?
Last shell command should print the parent return value (15)

*/

int main() {
	int n, status = 10, cpid, self_pid, parent_pid;

	printf("Parent pid = %d Status: %d\n",  getpid(), status);

	n = fork();

	if (n != 0) {
		//  parent code
		parent_pid = getppid();
		self_pid = getpid();
		printf ("Parent. PID: %d \t fork returned %d \t my parent is %d\n", self_pid, n, parent_pid);

		status = 100;
		sleep(5);		// verify status of child

		cpid = wait(&status);
		printf("Parent. PID: %d received from: %d Status: %d\n", self_pid, cpid, status);
	} else {		// child code
		parent_pid = getppid();
		self_pid = getpid();
		printf ("Child. PID: %d \t fork returned %d \t my parent is %d\n", self_pid, n, parent_pid);

		sleep(10);

		printf("Child. Status: %d\n", status);
		printf("Child. Complete\n");
		char test[6] = "green";
		status = 120;
		exit(42);
	}

	printf("Parent. Complete\n");
	exit(15);
}
