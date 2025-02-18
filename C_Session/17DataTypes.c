#include <stdio.h>

#include <limits.h> // Limit informations in integer variables

#include <float.h> // Limit informatio in flotating point variables

int main() {
  puts("Data types and its range\n");
  printf("%-14s %6s %20s %s\n", "Type", "length", "Min", "Max");
  printf("%-14s %6s  %s %s\n", "==============", "======", "===================", "====================");
  printf("%-14s %6lu %20d %-23u\n", "unsigned char", sizeof(unsigned char), 0, UCHAR_MAX);
  printf("%-14s %6lu %20d %-23d\n", "char", sizeof(char), SCHAR_MIN, SCHAR_MAX);
  printf("%-14s %6lu %20d %-23u\n", "unsigned short", sizeof(unsigned short), 0, USHRT_MAX);
  printf("%-14s %6lu %20d %-23d\n", "short", sizeof(short), SHRT_MIN, SHRT_MAX);
  printf("%-14s %6lu %20d %-23u\n", "unsigned", sizeof(unsigned), 0, UINT_MAX);
  printf("%-14s %6lu %20d %-23d\n", "int", sizeof(int), INT_MIN, INT_MAX);
  printf("%-14s %6lu %20d %-23lu\n", "unsigned long", sizeof(unsigned long), 0, ULONG_MAX);
  printf("%-14s %6lu %20ld %-23ld\n", "long", sizeof(long), LONG_MIN, LONG_MAX);
  printf("%-14s %6lu %20Ld %-23Ld\n", "long long", sizeof(long long), LLONG_MIN, LLONG_MAX);
  printf("%-14s %2lu %20d %-23Lu\n", "unsigned long long", sizeof(long long), 0, ULLONG_MAX);
  printf("-----------------------------------------------------------------\n");
  printf("%-14s %6lu %20e %-23e\n", "float", sizeof(float), FLT_MIN, FLT_MAX);
  printf("%-14s %6lu %20e %-23e\n", "double", sizeof(double), DBL_MIN, DBL_MAX);
  printf("%-14s %6lu %20Le %-23Le\n", "long double", sizeof(long double), LDBL_MIN, LDBL_MAX);
  return 0;
}
