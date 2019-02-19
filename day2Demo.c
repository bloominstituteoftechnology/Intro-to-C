#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char a[128];
  char *b = malloc(128); // malloc requires stdlib.h
  a[0] = 'G';
  a[1] = 'e';
  a[2] = 'm';
  a[3] = 'm';
  a[4] = 'a';
  a[5] = '\0'; // null terminator

  *(b + 0) = 'S';
  *(b + 1) = 'a';
  *(b + 2) = 'v';
  *(b + 3) = '\0';

  printf("%s\n", a);
  printf("%s\n", b);

  typedef int(*reduce_cb) (int accumulator, int current);
  int sum(int a, int b) {
    return a + b;
  }
    int producet(int a, int b) {
    return a * b;
  }

  int reduce(int *args, int length, int memo, reduce_cb cb)
  //
  {
    int accumulator = memo;
    for (int i = 0; i < length; i++) {
      accumulator + reduce_cb(accumulator, *(args+1));
    }
  }

  return 0;
}