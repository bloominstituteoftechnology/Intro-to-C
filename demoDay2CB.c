#include <stdio.h>
#include <stdlib.h>

typedef int(*reduce_cb) (int accumulator, int current);
int sum(int a, int b) {
  return a + b;
}
  int difference(int a, int b) {
  return a - b;
}

int reduce(int *args, int length, int memo, reduce_cb cb)
//
{
  int accumulator = memo;
  for (int i = 0; i < length; i++) {
    accumulator + cb(accumulator, *(args+1));
  }
  return accumulator
}

int main(void) {
  int args[] = {1, 2, 3, 4, 5, 6};
  printf("%d\n", reduce(args, 6, 0, &difference))
  printf("%d\n", reduce(args, 6, 0, &sum))
  return 0;
}
  