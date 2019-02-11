#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!

*/

// translation of function below
// int -- the datatype output will be integer 
// fizzbuzz -- will be it's name 
// int n -- it will take in an integer, n is the input placeholder 
int fizzbuzz(int n)

{ int counter = 0; // initialize a counter of the datatype 'int'
    for (int i=1; i<=n; i++)  //then iterate n times, for int datatype
    {
        // number divisible by 3 and 5 will always be divisible by 15
        if (i % 15 == 0) // mod operator outputs the remainder        
            printf ("FizzBuzz\n");  //printf --- 'print formatted'
          
        else if ((i % 3) == 0)     
            printf("Fizz\n", i);                  
          
        else if ((i % 5) == 0)                        
            printf("Buzz\n", i);                  
      
        else // Increment the counter variable         
            counter = counter + 1;              
    }
    return counter; //return the counter 
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
