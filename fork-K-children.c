// Generation of K children process

#define K 3

int
main()
{
int i;

for(i=0; i<K; i++) {   // for(i=0; i<K && fork(); i++)
  printf("I'm process %d i = %d %d\n", getpid(), i, getppid());
  if(fork() == 0)
    break;
  }

printf("Body of process %d with parent %d and i = %d\n",  getpid(), getppid(), i);


exit(0);
}
