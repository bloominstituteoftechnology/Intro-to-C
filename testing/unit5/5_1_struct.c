#include <stdio.h>

// declared structure 'student' with components 'firstName', 'lastName', etc
struct student
{
    char firstName[30];
    char lastName[30];
    int birthYear;
    double aveGrade;
};

void printStudent(struct student stud);
int main(void)
{
    //! showMemory(start=65520)
    // instantiated two instances of the structure type with some initializations
    struct student me = {"Petra", "Bonfert-Taylor", 1989, 3.5};
    struct student you = {"Remi", "Sharrock", 2005, 3.5};
    // move printf lines into function
    // printf("Name: %s %s\n", me.firstName, me.lastName);
    // printf("Year of birth: %d\n", me.birthYear);
    // printf("Average grade: %.2lf\n", me.aveGrade);

    printStudent(me);
    ptintStudent(you);
    return 0;
}

void printStudent(struct student stud)
{
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
    printf("Year of birth: %d\n", stud.birthYear);
    printf("Average grade: %.2lf\n", stud.aveGrade);
}