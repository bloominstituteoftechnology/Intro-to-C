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

void set_name(struct animal *p, char *name)
{
    //(*p).name = name;
    p->name = name; // -> is syntactic sugar
}

struct animal *create_animal(char *name, int leg_count)
{
    // Allocate space for a struct animal
    struct animal *p = malloc(sizeof(struct animal));

    // Set fields
    p->name = name;
    p->leg_count = leg_count;
    p->date_of_birth = time(NULL); // now

    // Return pointer to animal
    return p;
}

int main(void)
{
    int a;
    
    int *d = malloc(sizeof(int));
    *d = 37;

    struct animal b;
    struct animal c = { .name = "seagull", .leg_count = 2};

    struct animal *e = create_animal("chicken", 2);

    printf("sizeof(struct animal): %ld\n", sizeof(struct animal));
    printf("sizeof(struct animal *): %ld\n", sizeof(struct animal *));

    a = 12;

    b.name = "goat";
    b.leg_count = 4;
    b.date_of_birth = time(NULL); // init DOB to now

    print_animal(&b);

    set_name(&c, "human");

    print_animal(&c);

    print_animal(e);

    return 0;
}