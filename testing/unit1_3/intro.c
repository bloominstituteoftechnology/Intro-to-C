// distinguish between and give examples of integer, double and character data
// declare a variable of type char
// declare a variable of type double
// assign a character to a variable of type char
// assign a decimal to a variable of type double
// use the format specifier %c to read character using scanf and print characters using printf
// use the format specifier %lf to read decimals using scanf
// use the format specifier %lf with modifiers to print decimals to a given precision
// predict results of integer division in C
// explain the importance of conversion between integer and double data types
// use casting to convert between integer and double data types
// create C-programs that perform tasks involving user input, integer and floating point arithmetic operations and output to the screen

// Declare, assign and print characters with the %c format specifier
#include <stdio.h>
int main(void)
{
    char letter;  //DECLARE A CHARACTER VARIABLE
    letter = 'a'; //DEFINE or INITIALIZE or ASSIGN a character value
    printf("The letter is %c", letter);
    return 0;
}

// print characters with %c
#include <stdio.h>
int main(void)
{
    char letter1 = 'i';
    char letter2 = 'n';
    char letter3 = 'C';
    printf("Programming %c%c %c", letter1, letter2, letter3);
    return 0;
}

// Read characters from the user input
#include <stdio.h>
int main(void)
{
    char letter, letter2;
    printf("Please enter two letters separated by a comma: ");
    // printf("Please enter two letters separated by a space: ");
    // printf("Please enter two letters: "); // without a space
    scanf("%c,%c", &letter, &letter2);
    printf("I read the letters %c and %c.\n", letter, letter2);
    return 0;
}

#include <stdio.h>
int main(void)
{
    char user_input;
    scanf("%c", &user_input);
    printf("++++%c++++\n", user_input);
    printf("+++%c%c%c+++\n", user_input, user_input, user_input);
    printf("++%c%c%c%c%c++\n", user_input, user_input, user_input, user_input, user_input);
    printf("+%c%c%c%c%c%c%c+\n", user_input, user_input, user_input, user_input, user_input, user_input, user_input);
    printf("%c%c%c%c%c%c%c%c%c\n", user_input, user_input, user_input, user_input, user_input, user_input, user_input, user_input, user_input);
    return 0;
}