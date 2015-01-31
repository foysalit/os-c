/*
fork0. c
Illustrates system call fork

*/

int
main() {


printf("I'm the parent, my PID is %d, my parent is process %d\n",
           getpid(), getppid());

if (fork() == 0){
	// branch is for the parent
	sleep (25);
}
printf("This sentence has been printed by process: %d my parent is process %d\n",
        getpid(), getppid());

// who is process number 1 ?? 

exit(43);  // return 0;
}
