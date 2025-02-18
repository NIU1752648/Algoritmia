// A string is a vector of type char which ends with '\0'=0
#include <stdio.h>

#include <string.h>

int main() {
  char string1[21] = {
    'H',
    'e',
    'l',
    'l',
    'o',
    0
  };
  char string2[21] = "Hello"; // this adds 0 at the end
  char message[] = "Hello world"; // this adapts the length of the vector and ends with 0

  printf("%s\n", message);
  message[7] = 0;
  printf("%s\n", message);

  // Till here we where not using the library string.h
  /* functions
  long int strlen ( char *string );
  char *strcpy ( char *destination, char *source );
  char *strncpy ( char *destination, char *source, int num-de-chars );
  char *strcat ( char *destination, char *source );
  char *strncat ( char *destination, char *source, int num-de-chars );
  char *strdup ( char *source );
  int *strcmp ( char *string_1, char *string_2 );
  int *strncmp ( char *string_1, char *string_2, int num-de-chars );
  char *strchr ( char *string, char character );
  char *strrchr ( char *string, char character );
  */

  strcpy(message, "Hello world");
  printf("'%s' has %ld characters\n", message, strlen(message));
  printf("The difference of the first different character between '%s' and '%s' is %d\n", string1, string2, strcmp(string1, string2));
  printf("The difference of the first different character between '%s' and '%s' is %d\n", string1, message, strcmp(string1, message));
  return 0;
}
