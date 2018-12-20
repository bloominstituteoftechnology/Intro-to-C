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

// Read integers and doubles with scanf()
#include <stdio.h>
int main(void)
{
    int age;
    double height;
    printf("What is your age?");
    scanf("%d", &age);
    printf("What is your height?");
    scanf("%lf", &height);
    printf("You are %d years old and %.2lf meters tall.", age, height);
    return 0;
}

#include <stdio.h>
int main(void)
{
    int age;
    double height;
    printf("What is your age and height (separate with spaces)?");
    scanf("%d %lf", &age, &height);
    printf("You are %d years old and %.2lf meters tall.", age, height);
    return 0;
}

// convert between units (km to miles), a program that reads a decimal number representing a distance in kilometers and prints out the corresponding distance in miles with 6 decimal places.
// one kilometer equals 0.621371 miles.
#include <stdio.h>
int main(void)
{
    double dist;
    scanf("%lf", &dist);
    double km = dist * 0.621371;
    printf("%lf", km);
    return 0;
}

// division
#include <stdio.h>
int main(void)
{
    // integer division
    printf("5/2 equals %d\n", 5 / 2); // 2
    // floating point division
    printf("5.0/2.0 equals %lf\n", 5.0 / 2.0); // 2.500000
    printf("5/2.0 equals %lf\n", 5 / 2.0);     // 2.500000
    printf("5.0/2 equals %lf\n", 5.0 / 2);     // 2.500000
    return 0;
}

// reads a decimal number representing a temperature in degrees Celsius and prints out the corresponding temperature in degrees Fahrenheit with 1 decimal place.
// Temperature (°F) = Temperature (°C) × 9.0 / 5.0 + 32.0
#include <stdio.h>
int main(void)
{
    int user_n;
    scanf("%d", &user_n);
    printf("%.1lf", user_n * 9.0 / 5.0 + 32.0);
    return 0;
}

#include <stdio.h>
int main(void)
{
    // pay 166 dollars using 20-dollar bills, rest with 1-dollar bills
    int twenties = 166 / 20;
    int rest = 166 % 20;
    printf("I will pay %d dollars with 20-dollar bills.\n", twenties * 20);
    printf("I will then pay %d dollars with 1-dollar bills.\n", rest);
    return 0;
}

// take as input the number of matches to be boxed up followed by the size of a each box.
// print out the number of full boxes followed by the number of remaining matches.
#include <stdio.h>
int main(void)
{
    int matches, boxes;
    scanf("%d", &matches);
    scanf("%d", &boxes);
    int m_boxes = matches / boxes;
    printf("%d\n", m_boxes);
    printf("%d", matches % boxes);
}

// Convert integers to double
#include <stdio.h>
int main(void)
{
    int iOne;
    int iTwo;
    double dOne;
    printf("Please enter two integers: ");
    scanf("%d %d", &iOne, &iTwo);
    dOne = (double)iOne;
    printf("dOne/iTwo equals %lf\n", dOne / iTwo);
    return 0;
}

// Convert double to integers
#include <stdio.h>
int main(void)
{
    double dOne, dTwo;
    int iOne, iTwo;
    printf("Please enter two decimals: ");
    scanf("%lf %lf", &dOne, &dTwo);
    printf("I read dOne = %lf, dTwo = %lf.\n", dOne, dTwo);
    iOne = (int)dOne;
    iTwo = (int)dTwo;
    printf("iOne = %d, iTwo = %d.\n", iOne, iTwo);
    printf("%d / %d = %d.\n", iOne, iTwo, iOne / iTwo);
    return 0;
}

#include <stdio.h>
int main(void)
{
    double dOne, dTwo;
    int iOne, iTwo, result;
    scanf("%lf %lf", &dOne, &dTwo);
    iOne = (int)dOne;
    iTwo = (int)dTwo;
    result = iOne / iTwo;
    printf("%d", result);
    return 0;
}

#include <stdio.h>

int main(void)
{
    double cement;
    int bags;
    scanf("%lf", &cement);
    bags = cement / 120 + 1; //we know that the amount of cement is not a multiple of 120
    printf("%d", bags * 45);
    return (0);
}