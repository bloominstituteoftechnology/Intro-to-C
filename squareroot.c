#include <stdio.h>
#include <math.h>

int squareroot(double base, double exponent);

int main()
{
    squareroot(128934, 0.5);
    return 0;
}

int squareroot(double base, double exponent){
    double result;

    // calculates the power
    result = pow(base, exponent);

    printf("%.1lf^%.1lf = %.2lf", base, exponent, result);
    
    return 0;
}
