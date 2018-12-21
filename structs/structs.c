#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/* 
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/
typedef struct Person {
    char name;
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

// char *string_dup(char *src)
// {
//     char *dup = malloc(strlen(src));
//     int i;
//     for (i = 0; i < strlen(src); i++) {
//         *(dup+i) = *(src+i); 
//     }
//     *(dup + strlen(src))='\0';
//     // free(dup);
//     return dup;
// }
Person *createPerson(char *name, int age, int height, int weight)
{
    // Person *newPerson;
    // printf("size of newPerson struct:%d\0", sizeof(newPerson));
    char nameDup = string_dup(name);
    Person *newPerson = malloc(sizeof(Person));
    printf("size of newPerson struct:%d\0", sizeof(Person));
    
    // // *newPerson = (struct Person) {*nameDup,age, height,weight};
    newPerson->name = nameDup;
    newPerson->age = age;
    newPerson->height = height;
    newPerson->weight = weight;
    // printf("Age: %d\n", newPerson->age);
    return newPerson;
}

/*
    Given a pointer to a Person struct, frees up the memory that holds the
    Person's name as well as the memory that holds the Person instance.
*/
void destroyPerson(Person *who)
{
    // char *name = (*who).name;
    // printf("name: %c", *name);
    // free(name);
    // free((*who).name);
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