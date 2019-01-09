#include <string.h>
#include <stdlib.h>

struct animal {
    char *name;
    int leg_count;
};

struct animal *animal_new(char *name, int leg_count)
{
    struct animal *a = malloc(sizeof(struct animal));

    a->name = malloc(strlen(name) + 1); // +1 for NUL terminator
    strcpy(a->name, name);
    a->leg_count = leg_count;

    return a;
}

void animal_free(struct animal *a)
{
    free(a->name);
    free(a);
}

int main(void)
{
    struct animal *goat = animal_new("goat", 4);

    // Do goat things

    animal_free(goat);

    return 0;
}



