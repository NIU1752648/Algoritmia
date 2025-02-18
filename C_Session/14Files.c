/* Adding data to files or creating files as an output has a syntax
   very similar to printf, but using fprintf (file printf).
   Getting data from files also has a syntax very similar to scanf
   and uses fscanf.
   Both functions (fprintf, fscanf) have a first argument which is a
   channel to comunicate with a file (a variable of type FILE)     */
#include <stdio.h>

int main() {
  FILE * channeltofile;
  int i, po;

  channeltofile = fopen("out.txt", "w"); // "w" means "write"
  if (channeltofile == NULL) {
    printf("We cannot create the file!");
    return 1;
  }
  po = 1;
  for (i = 1; i <= 10; i++) {
    po = 3 * po;
    fprintf(channeltofile, "3^%d = %d\n", i, po);
  }
  fclose(channeltofile); // This file must exist now!

  // Now we will read the file
  channeltofile = fopen("out.txt", "r"); // "r" means "read"
  if (channeltofile == NULL) {
    printf("We cannot open the file for reading!");
    return 1;
  }

  while (fscanf(channeltofile, "3^%d = %d\n", & i, & po) != EOF) printf("i=%d and po=%d\n", i, po);

  fclose(channeltofile);
  return 0;
}
