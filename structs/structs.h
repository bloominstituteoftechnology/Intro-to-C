#ifndef structs_h
#define structs_h

typedef struct Person {
    char *name;
    int age;
    int height;
    int weight;
} Person;

Person *createPerson(char *name, int age, int height, int weight);

void destroyPerson(Person *who);

#endif