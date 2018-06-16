#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int fizzbuzz(int n)
{
int i;
//Most C code that I have seen declares i like this so I assume its best practice.
int count = 0;
//Count is included to return the number of i passed in that does not go into any of the three categories.
for(i = 0; i<=n; i++) {
    if((i%3) && (i%5)== 0){
        printf("FizzBuzz\n");
    }
    //Messed around with the above function a bit apparently I only need to declare the value at the end.
    //\n is just a new line thing. 
    else if(i%3 == 0)
        {
            printf("Fizz\n");
        }
    else if(i%5 == 0)
    {
        printf("Buzz\n");
    }
    else{
        count++;
    }
}
return count;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
