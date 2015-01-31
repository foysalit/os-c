int i, j, *pk;

int
main(){

scanf("%d", &i);
j=2;
j = j /i;

printf("%d\n", j);

// pk = &i;

pk = 0;

scanf("%d", pk); // try to write in a memory location
		//out of user domain 
printf("i contains: %d %d\n", i, *pk);
}
 
 
