#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/* 
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/
typedef struct Person {
    char *name;
    int age;
    int height;
    int weight;

} Person;

/*
    Creates an instance of the Person struct that receives all the relevant
    pieces of data associated with a Person instance.
    Allocates the appropriate amount of memory to hold an instance of the 
    Person struct, and then sets the struct's fields with the input data.
    When setting the `name` field, use your previously-built string_dup
    function, which handles the allocation of memory for the new string.
*/
Person *createPerson(char *name, int age, int height, int weight)
{
    // Allocate memory for our struct
    Person *person = malloc(sizeof(Person));
    
    // Initialize the value of the struct
    // Allocate memrory for the string (dynamic type) bytes varies
    // Why string_dup name: the name string in passed in from somewhere else and in struct, structs need to own their data inside
    // If we just pass in the outside string and have a pointer to it, when the outside string is deallocated, struct still thinks it has reference to it and it will cause problem, so we want to duplicate the string so struct can own a copy
    person->name = string_dup(name);
    person->age = age;        // int is static type (4 bytes) so don't need memory allocation
    person->height = height;
    person->weight = weight;
    
    return person;
}

/*
    Given a pointer to a Person struct, frees up the memory that holds the
    Person's name as well as the memory that holds the Person instance.
*/
void destroyPerson(Person *who)
{
    // Need to free memory allocated to name, then the struct, 
    // Free in last in, first out order, but the struct is always last
    free(who->name);
    free(who);
}

#ifndef TESTING
int main(void)
{
    Person *tony = createPerson("Tony Stark", 32, 64, 140);

    printf("  Name: %s\n", tony->name);
    printf("   Age: %d\n", tony->age);
    printf("Height: %d\n", tony->height);
    printf("Weight: %d\n", tony->weight);

    destroyPerson(tony);

    return 0;
}
#endif