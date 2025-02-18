// Structures in C
#include<stdio.h>

typedef struct {
  double x;
  double y;
  double z;
}
point;

int main() {
  point p;
  point ps[16];
  int i, j;

  printf("Enter a value for coordinate x of p: ");
  scanf("%lf", & p.x);
  printf("Enter a value for coordinate y of p: ");
  scanf("%lf", & p.y);
  printf("Enter a value for coordinate z of p: ");
  scanf("%lf", & p.z);
  printf("p has coordinates (%g,%g,%g)\n", p.x, p.y, p.z);

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      ps[4 * i + j].x = (double) i;
      ps[4 * i + j].y = (double) j;
      ps[4 * i + j].z = (double) i * i + j * j;
    }
  }

  for (i = 0; i < 16; i++) printf("ps[%d] has coordinates (%g,%g,%g)\n", i, ps[i].x, ps[i].y, ps[i].z);

  ps[1] = ps[5];

  for (i = 0; i < 16; i++) printf("ps[%d] has coordinates (%g,%g,%g)\n", i, ps[i].x, ps[i].y, ps[i].z);

  return 0;
}
