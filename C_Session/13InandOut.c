// printf is a function that has been used before which has a lot of options.
// Moreover, there are other functions which allow you to obtain or show data.
#include <stdio.h>

int main() {
  int InvoiceNumber = 5;
  double InvoiceAmount = 225.128;
  char InvoiceClient[] = "Pierre de Fermat";

  printf("The invoice number %03d charges %8.2lf Euros to %s\n", InvoiceNumber, InvoiceAmount, InvoiceClient);

  /* Special characters include:
   \n newline
   \f form feed
   \b gackspace
   \t tab
   \nnn ASCII nnn
   \Onnn ASCII (octal)
   \0xnn ASCII nn (hecadecimal)
   \\ backslash
   %% character %

   The syntax for printing values:
   %[-][0][width[.precission]][l][u]type
   - means left align
   0 means fill with 0 on the left
   l adds to the type the long version
   u adds to the type the unsigned version
   The possible types are:
      d or i   integer
      u   unsigned ineger
      o   integer in octal base
      x   integer in hexadecimal base
      c   character
      s   string
      f   real value (floating point)
      e   exponential form
      g   real vaule in form e, f or d
  */

  printf("The same value %7.3lf can be written as %lf, %e or %g\n", InvoiceAmount, InvoiceAmount, InvoiceAmount, InvoiceAmount);

  // The same sintax works for the scanf function:
  printf("Enter an integer and a float separated by comma\n");
  scanf("%d,%lf", & InvoiceNumber, & InvoiceAmount);
  printf("The values are %d and %g\n", InvoiceNumber, InvoiceAmount);

  /* There are other funtions for printing and getting information:
   putchar(char)
   puts(string)
   char=getchar() // une character from the keyboard
   gets(string)   // string till it finds EOF or \n
  */
  puts("This is a string");
  puts("another string");
  putchar('\n');

  return 0;
}
