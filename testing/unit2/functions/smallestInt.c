// use min() in your main function to work your way through an entire list of numbers in order to find its minimum. The first number you read gives the number of elements in the list of integers under consideration. You will then read the integer values, using min() to keep only the smallest integer read at each step. In the end, please print out the smallest integer in the list.
// Input
// 10
// 4 3 6 2 6 8 9 8 5 4
// Output
// 2
#include <stdio.h>
int min(int, int);
int main(void)
{
    int num, i, user_i, result;
    scanf("%d", &num);
    int arr[num];
    for (i = 0; i < num; i++)
    {
        scanf("%d", &user_i);
        arr[i] = user_i;
    }
    for (i = 1; i < num; i++)
    {
        result = min(arr[i - 1], arr[i]);
        arr[i] = result;
    }
    printf("%d", result);
    return 0;
}
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
// solution
#include <stdio.h>
int min(int, int);
int main(void)
{
    int num, i, user_i, minimum;
    scanf("%d", &num);
    scanf("%d", &minimum);
    for (i = 1; i < num; i++)
    {
        scanf("%d", &user_i);
        minimum = min(minimum, user_i);
    }
    printf("%d", minimum);
    return 0;
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// the recursive factorial example
// #include <stdio.h>
// // 5! = 1*2*3*4*5
// // n! = 1*2*3*...*(n-1)*n
// //recursion : one function calls itself
// int factorial(int);
// int main(void) {
//     int n, facto;
//     printf("Please enter a positive integer: ");
//     scanf("%d",&n);
//     if(n<0){
//         printf("%d is negative! Aborting..\n", n);
//     }else{
//         facto = factorial(n);
//         printf("%d! = %d.\n", n , facto);
//     }
//     return 0;
// }
// int factorial(int n){
//     int result;
//     if(n==0){
//         result=1;
//     }else{
//         result = n * factorial(n-1);
//     }
//     return result;
// }

