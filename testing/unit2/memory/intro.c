// Identify components of the Von Neumann architecture model
// Recall how computer memory is organized and addressed
// Use the sizeof() function to find out how much space a variable of a certain type uses up in memory on a given computer system
// Recognize overflow and roundoff errors and their causes
// Identify the scope of a variable within a C program including blocks and functions

// compute space for tracking codes
// Your program should first read an integer number indicating how many tracking codes you plan on entering. Next, for each successive tracking code your program should read in the integer length of code followed by a space and then the type of code ('i' for integer, 'd' for decimal, or 'c' for character). Finally your program should print the total amount of space required to store all of the tracking codes (in bytes). If the user enters an incorrect type for any tracking number, the program should print 'Invalid tracking code type' and exit.
// Examples
// Input:
// 3 // first input
// 10 i
// 7 c
// 12 d
// Output:
// 143 bytes

#include <stdio.h>
int main(void)
{
    int num, user_i, i;
    int result = 0;
    char type;
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d %c", &user_i, &type);
        if (type == 'i')
        {
            result += user_i * sizeof(int);
        }
        else if (type == 'c')
        {
            result += user_i * sizeof(char);
        }
        else if (type == 'd')
        {
            result += user_i * sizeof(double);
        }
        else
        {
            printf("Invalid tracking code type");
            return 0;
        }
    }
    printf("%d bytes", result);

    return 0;
}

// Modify an integer variable value using a function with pointers
#include <stdio.h>
void addThree(int *);
int main()
{
    //! showMemory(start=65520)
    int a = 5;
    addThree(&a);
    printf("inside main, value of a: %d\n", a);
    return 0;
}
void addThree(int *a)
{
    *a = *a + 3;
    printf("inside addThree, value of a: %d\n", *a);
}