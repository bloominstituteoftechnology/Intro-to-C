#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/* 
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

/*
    Creates an instance of the Person struct that receives all the relevant
    pieces of data associated with a Person instance.

    Allocates the appropriate amount of memory to hold an instance of the 
    Person struct, and then sets the struct's fields with the input data.
    When setting the `name` field, use your previously-built string_dup
    function, which handles the allocation of memory for the new string.
*/
struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *a_person = malloc(sizeof(struct Person));

    a_person->name = string_dup(name);
    a_person->age = age;
    a_person->height = height;
    a_person->weight = weight;

    return a_person;
}

/*
    Given a pointer to a Person struct, frees up the memory that holds the
    Person's name as well as the memory that holds the Person instance.
*/
void Person_destroy(struct Person *who)
{
    if (who->name != NULL) {
        free(who->name);
    }

    if (who != NULL) {
        free(who);
    }
}

#ifndef TESTING
int main(void)
{
    struct Person *tony = Person_create("Tony Stark", 32, 64, 140);

    printf("  Name: %s\n", tony->name);
    printf("   Age: %d\n", tony->age);
    printf("Height: %d\n", tony->height);
    printf("Weight: %d\n", tony->weight);

    Person_destroy(tony);

    return 0;
}
#endif