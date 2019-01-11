#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


/* 
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/

//here I create my struct 
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
  //here malloc the space for the new struct
  Person *newStack = malloc(sizeof(Person));
  //I run the strndup function that duplicates the string,
  //I pass in the name of the string and its length as
  //paramenters
  newStack->name = strndup(name, strlen(name));
  newStack->age = age;
  newStack->height = height;
  newStack->weight = weight;
  return newStack;
}

/*
    Given a pointer to a Person struct, frees up the memory that holds the
    Person's name as well as the memory that holds the Person instance.
*/
void destroyPerson(Person *who)
{
  //here I free the space on the heap
  free(who);
}

#ifndef TESTING
int main(void)
{
    //here I create my person struct
    Person *tony = createPerson("Tony Stark", 32, 64, 140);
    //here I print up the structs values
    printf("Name: %s\n", tony->name);
    printf("Age: %d\n", tony->age);
    printf("Height: %d\n", tony->height);
    printf("Weight: %d\n", tony->weight);

    //here I destroy the person and free on space on memory
    destroyPerson(tony);

    return 0;
}
#endif