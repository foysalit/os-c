#include <stdio.h>
int 
main (int argc, char **argv) { 
  FILE * fs, *fd;
  char c;
  char buffer[1024];
  int n_elem;
  

// Soluzione 1
  fs = fopen (argv[1], "r");
  fd = fopen (argv[2], "w");
  while (!feof (fs)) {
    // fscanf(fs,"%c", &c); 
    // fprintf(fd, "%c", c);
    fputc (fgetc (fs), fd);
  }
  fclose(fs);
  fclose(fd);
  
// Soluzione 2
  fs = fopen (argv[1], "r");
  fd = fopen (argv[2], "w");
  while (!feof (fs)) {
    fgets (buffer, 132, fs);
    fputs (buffer, fd);
  }
  fclose(fs);
  fclose(fd);
  
//  Soluzione 3
  fs = fopen (argv[1], "rb");
  fd = fopen (argv[2], "wb");
  while (!feof (fs)) {
    n_elem = fread (buffer, 1, sizeof (buffer), fs);
    n_elem = fwrite (buffer, 1, n_elem, fd);
  }
  fclose(fs);
  fclose(fd);
}
