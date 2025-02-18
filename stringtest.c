#include <stdio.h>
#include <string.h>

int main() {
	char a[] = "hola";
	printf("Sizeof dona: %d\n", sizeof(a)/sizeof(a[0]));
	printf("Strlen donw: %d\n", strlen(a));
	return 0;
}
