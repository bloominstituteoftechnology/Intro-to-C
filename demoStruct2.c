#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct animal {
  char *name;
  int leg_count;
  time_t date_of_birth;
};

void print_animal(struct animal *x)
{
  printf("%s has %d legs\n", x->name, x->leg_count);
}

void set_name(struct animal *p, char *name) {
  // (*p).name = name
  p->name = name; // syntantical sugar
}

struct animal *create_animal(char *name, int leg_count)
{
  struct animal *p = malloc(sizeof(struct animal));

  p->name = name;
  p->leg_count = leg_count;
  p->date_of_birth = time(NULL);

  return p;
}

int main(void) {
  int a;
  int *d = malloc(sizeof(int));
  *d = 37;
  free(d);
  struct animal b;
  struct animal c = { .name = "seagull", .leg_count = 2};
  struct animal *e = create_animal("chicken", 2);
  printf("sizeof(struct animal): %ld\n", sizeof(struct animal));
  printf("sizeof(struct animal): %ld\n", sizeof(struct animal *));
  print_animal(e);
}

// int main(void)
// {
//   int a;
//   struct animal b;
//   struct animal c = {.name = "seagull", .leg_count = 2};

//   a = 12;
//   b.name = "goat";
//   b.leg_count = 4;
//   printf("%s has %d legs\n", b.name, b.leg_count);
//   printf("%s has %d legs\n", c.name, c.leg_count);
//   return 0;
// }