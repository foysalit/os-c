// illustrates the use of signal USR1 and SIG_IGN

#include <signal.h>

int
main (int argc, char ** argv) {

int i, ret, code;

if (argc > 1)
 signal(SIGUSR1, SIG_IGN);  // ignores the signal 

while (1) {  		   
  sleep (15);		 
}


}
