#include <stdio.h>
/* prototype function */
int string_to_int(char *s, char **bad);
int main(void) {
  // printf("Hello Woarld\n");
  char *p;
  printf("%d\n", string_to_int("124"))
  return 0;
}

int string_to_int(char *s, char **bad) {
  int a = 0;
  int v;
  while(*s) { // while *s is not the null terminator '\0'
    v = *s - 0;   // same as v = *s -48
    printf("a: %d\n", a)
    printf("v: %d\n", v)
    printf("s: %d\n", *s)
  }
  *bad = s;
  // We deference it and now we take the address of s and set it to *bad

  if (v < 0 || v > 9) {
    break;
  }
}