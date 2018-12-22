#include <stdio.h>
int sum(int x, int y)
{ //PARAMETERS
    int compute;
    printf("Starting the computation!\n");
    compute = x + y;
    printf("Finished the computation successfully!\n");
    return compute;
}
int main(void)
{
    int a, b;
    int result;
    printf("Please enter two integers: ");
    scanf("%d%d", &a, &b);
    printf("You entered %d and %d.\n", a, b);
    result = sum(a, b); //ARGUMENTS
    printf("Result of the sum = %d.\n", result);
    return 0;
}

// Differentiate the prototype and the definition of a function
// #include <stdio.h>
// int sum(int, int); //function PROTOTYPE
// int main(void) {
//     int a, b;
//     int result;
//     printf("Please enter two integers: ");
//     scanf("%d%d", &a, &b);
//     printf("You entered %d and %d.\n", a, b);
//     result = sum(a, b); //copies of the VALUES of the ARGUMENTS a and b
//     printf("Result of the sum = %d.\n", result);
//     return 0;
// }
// // Function DEFINITION
// int sum(int x, int y){ //values are copied into PARAMETERS x and y
//     int compute;
//     printf("Starting the computation!\n");
//     compute = x + y;
//     printf("Finished the computation successfully!\n");
//     return compute;
// }

// Decompose a problem into multiple functions
// #include <stdio.h>
// void printLine(int nCols, char pattern);
// void printTriangle(int nLines, char pattern);
// void printRectangle(int nLines, int nCols, char pattern);

// int main(void)
// {
//    int nCols;
//    int nLines;

//    printf("How many columns would you like? ");
//    scanf("%d", &nCols);
//    printLine(nCols, 'X');

//    printf("How many lines would you like? ");
//    scanf("%d", &nLines);
//    printTriangle(nLines, '*');
//    printf("\n");
//    printRectangle(nLines, nCols, '#');
// }

// void printLine(int nCols, char pattern)
// {
//    int i;
//    for (i = 0; i < nCols; i++)
//    {
//       printf("%c", pattern);
//    }
//    printf("\n");
// }

// void printTriangle(int nLines, char pattern)
// {
//    int line, cols;
//    for (line = 0; line < nLines; line++)
//    {
//       cols = line + 1;
//       printLine(cols, pattern);
//    }
// }
// void printRectangle(int nLines, int nCols, char pattern)
// {
//     int i;
//     for (i = 0; i < nLines; i++)
//     {
//         printLine(nCols, pattern);
//     }
// }

// program a smart unit converter
#include <stdio.h>
double meterConv(double);
double gramConv(double);
double tempConv(double);
int main(void)
{
    int num;
    double val, resultM, resultG, resultC;
    char unit;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%lf %s", &val, &unit);
        if (unit == 'm')
        {
            resultM = meterConv(val);
            printf("%lf ft\n", resultM);
        }
        else if (unit == 'g')
        {
            resultG = gramConv(val);
            printf("%lf lbs\n", resultG);
        }
        else if (unit == 'c')
        {
            resultC = tempConv(val);
            printf("%lf f\n", resultC);
        }
    }

    return 0;
}

double meterConv(double a)
{
    double feet;
    feet = a * 3.2808;
    return feet;
}

double gramConv(double a)
{
    double lbs = a * 0.002205;
    return lbs;
}
double tempConv(double a)
{
    double fahr = 32 + 1.8 * a;
    return fahr;
}