#ifndef structs_h
#define structs_h

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight);

void Person_destroy(struct Person *who);

#endif