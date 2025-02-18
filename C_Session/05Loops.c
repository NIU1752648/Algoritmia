#include <stdio.h>

int main() {
  int i, po = 1;
  // a loop with for
  // Sintax: for(initialization ; condition ; modification){ commands ...  }
  for (i = 1; i <= 10; i++) {
    po = 3 * po;
    printf("3^%d = %d\n", i, po);
  }
  // equivalently
  i = 1;
  po = 1;
  // Sintax: while(condition) { commands }
  while (i <= 10) {
    po = 3 * po;
    printf("3^%d = %d\n", i, po);
    i++;
  }
  // We can interrupt a loop with break; or go to the next iteration with cotinue;
  // The next example skips the multiple of 3 and stops if there is a multiple of 15
  i = 100;
  while (1) {
    if (i % 15 == 0) break;
    if (i % 3 == 0) {
      i++;
      continue;
    }
    printf("%d\n", i);
    i++;
  }
  return 0;
}
