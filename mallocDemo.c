#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *p = malloc(128); // #include <stdlib.h
  *(p+0) = 'G';
  p[0] = 'G';

  *(p+1) = 'e';
  *(1+p) = 'e';
  *(p+37) = 'm';
  37[p] = 'm'; // DO NOT DO THIS! IT WORKS BUT IS BAD FORM!

  // When using malloc always use free
  return 0;
}