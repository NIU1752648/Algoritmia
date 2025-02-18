// Program based on slides about structures by Lluís Alsedà

#include <stdio.h>

#include <stdlib.h>

#define FinalGrade(t, p)(0.6 * t + 0.4 * p)

typedef struct ALUDATA {
  char name[20], surname[40];
  float theory, pract, final;
  struct ALUDATA * next;
}
alumn;

void PrintList(alumn * );

int main() {
  alumn * start = NULL, * curr = NULL, * aux = NULL;
  FILE * grad;
  unsigned int i;

  grad = fopen("grades.txt", "r");
  if (grad == NULL) {
    printf("Error: we could not open the file\n");
    return 1;
  }

  while (!feof(grad)) {
    if ((aux = (alumn * ) malloc(sizeof(alumn))) == NULL) {
      printf("Error: we could not reserve the memory\n");
      return 1;
    }
    fscanf(grad, "%[a-zA-Z'. ];%[a-zA-Z'. ];%f;%f\n", aux -> name, aux -> surname, & (aux -> theory), & (aux -> pract));
    aux -> final = FinalGrade(aux -> theory, aux -> pract);
    aux -> next = NULL;
    if (curr) curr -> next = aux;
    else start = aux;
    curr = aux;
  };
  fclose(grad);

  printf("Original order (alphabetical by name):\n");
  PrintList(start);

  printf("\nWe switch first and second positions in the linked list. This implies modifying the value of start\n");
  curr = start;
  aux = start -> next;
  start = aux;
  curr -> next = start -> next;
  start -> next = curr;

  PrintList(start);

  printf("\nWe apply the permutation 0->3; 3->2; 2->1; 1->0\n");

  unsigned int perm[4] = {
    3,
    0,
    1,
    2
  }; // permutation defined as the image of {0,1,2,3}
  alumn * address[4]; // to save the adress of each element in the list

  curr = start;
  i = 0;
  while (curr) {
    address[perm[i]] = curr;
    curr = curr -> next;
    i++;
  }
  start = address[0];
  for (i = 0; i < 3; i++) address[i] -> next = address[i + 1];
  address[3] -> next = NULL;

  PrintList(start);

  printf("\nWe remove the second element of the list\n");
  aux = start -> next;
  start -> next = aux -> next;
  free(aux); // Very important!!!!

  PrintList(start);

  return 0;
}

void PrintList(alumn * first) {
  while (first) {
    printf("%s %s %f %f %f\n", first -> name, first -> surname, first -> theory, first -> pract, first -> final);
    first = first -> next;
  }
}
