#include <stdio.h>

struct student
{
    char firstName[5];
    char lastName[5];
    int birthYear;
    double aveGrade;
};

int main(void)
{
    //! showMemory(start=65520)
    struct student me;
    printf("Size of struct student is %zu.\n", sizeof(struct student));
    printf("Size of firstName is %zu.\n", sizeof(me.firstName));
    printf("Size of lastName is %zu.\n", sizeof(me.lastName));
    printf("Size of birthYear is %zu.\n", sizeof(me.birthYear));
    printf("Size of aveGrade is %zu.\n", sizeof(me.aveGrade));

    return 0;
}

// Size of struct student is 24.
// Size of firstName is 5.
// Size of lastName is 5.
// Size of birthYear is 4.
// Size of aveGrade is 8.