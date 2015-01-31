/* copy.c */

#include <stdio.h>
#include <fcntl.h>

#define BUFDIM 1024

char buffer[ BUFDIM ];

int
main( int argc, char ** argv ){
int oldfd, newfd; /* file descriptors */

if ( argc != 3 ) {
    fprintf(stderr,"usage: %s oldfile newfile\n", argv[0] );
    exit( -1 );  // return -1;
  }
  /* open source file in read-only mode */
  oldfd = open( argv[1], O_RDONLY );
  if ( oldfd == -1 ){
    fprintf(stderr,"%s: cannot open file %s\n", argv[0], argv[1] );
    exit(-1);
  }
/* create dest. file in read-write mode */
  newfd = creat( argv[2], 0666 );
  if ( newfd == -1) {
    fprintf(stderr,
     "%s: cannot create file %s\n",
      argv[0], argv[2]);
    exit( -1 ); 
  }
  copy( oldfd, newfd );
  exit( 0 );
}
 
copy(int oldfd, int newfd ){
  int count;
  while ((count = read( oldfd, buffer, BUFDIM)) > 0 )
    write( newfd, buffer, count );
}
