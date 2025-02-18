#include <stdio.h>

int length(char *charsq) {
	int i = 0;
	while (*charsq) {
		i++;
		charsq++;
	}
	return i;
}

void extreurecadena(char *instr, int a, int b, char *outstr) {
	char *start = instr + a;
	char *end = instr + b;
	while (start < end) {
		*outstr = *start;
		start++;
		outstr++;
	}
	*outstr = '\0';
}

int main() {
	char a[] = "hola mundo";
	char b[10];
	
	extreurecadena(a, 2, 7, b);
	printf("%s\n", a);
	printf("%s\n", b);
}
