/*
fork00.c
Illustrates system call fork
*/

int
main() {

printf("PID %d\n", getpid());

fork();
printf("my PID is %d, my parent is process %d\n",
           getpid(), getppid());
}
