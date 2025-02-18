// malloc, calloc, free and realloc are functions which allow to reserve and free memory while executing the program
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void main() {
  char * buffer, * aux;
  /* Reservation of memory has always to be checked! */
  if ((buffer = (char * ) malloc(10 * sizeof(char))) == NULL) {
    printf("malloc failed!\n");
    exit(1);
  }
  strcpy(buffer, "Bangalore");
  printf("\nThe string contains: %s\n", buffer);
  /* Modifying the reservation has also to be checked! */
  if ((aux = (char * ) realloc(buffer, 30 * sizeof(char))) == NULL) {
    printf("realloc failed!\n");
    exit(1);
  }
  buffer = aux;
  printf("\nSize of the modified buffer.\n");
  printf("\nThe sytring has still: %s\n", buffer);
  strcpy(buffer, "Santa Perpetua de Mogoda");
  printf("\nNow the string is: %s\n", buffer);
  /* Free the memory */
  free(buffer);
  buffer = NULL; /* Avoids to use the previous possition of buffer */
}
