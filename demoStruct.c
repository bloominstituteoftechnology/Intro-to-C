#include <stdio.h>
struct animal {
  char *name;
  int leg_count;
};

int main(void)
{
  int a;
  struct animal b;
  struct animal c = {.name = "seagull", .leg_count = 2};

  a = 12;
  b.name = "goat";
  b.leg_count = 4;
  printf("%s has %d legs\n", b.name, b.leg_count);
  printf("%s has %d legs\n", c.name, c.leg_count);
  return 0;
}