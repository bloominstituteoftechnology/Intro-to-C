#include <stdio.h>
#include <string.h>


/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/

// from https://stackoverflow.com/a/23840699
char *
itoa (int value, char *result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

/*
int fizzbuzz(int n)
{
  for(int i = 0; i <= n; i++) {
    // printf(n);
    char outstr[12] = "";

    int strpos = 0;

    itoa(n, outstr, 10);

    // strpos += strlen(outstr);
    // printf("%d", strpos);
    if (i % 3 == 0) 
      outstr[strpos] = "fizz";
    // strpos += strlen(outstr);
    // printf("%d", strpos);
    else if (i % 5 == 0) 
      outstr[strpos] = "buzz";
    // strpos += strlen(outstr);
    // printf("%d", strpos);
    outstr[strpos] = '\0';
    else 
      //printf("%s", outstr);
    printf("\n");
  }
  return 0;
}
*/


char * fizzbuzz(int i, char * outstr)
{
        // printf(n);
        // char outstr[12] = "";

        if (i % 3 == 0 && i % 5 == 0) 
        {
          outstr = "Fizzbuzz!";
          // return "Fizzbuzz!";
            // printf("Fizzbuzz!");
          }
        else if (i % 3 == 0) 
        {
          outstr = "Fizz";
          // return "Fizz";
            // printf("Fizz");

        }

        else if (i % 5 == 0) 
        {
          outstr = "Buzz!";
          // return "Buzz";
            // printf("Buzz");
        }

        else 
        {
          outstr = itoa(i, outstr, 10);
          // return itoa(i, "", 10);
            // printf("%d", i);
        }
        // printf("\n");
          return outstr;
    // return 0;
}


#ifndef TESTING
int main(void)
{
    // loop through fizzbuzz
    int n = 20;
    char * output = (char*) malloc(20 * sizeof(char));
    for(int i = 0; i <= n; i++) {
        fizzbuzz(i, output);
        printf("i: %d %s %s\n", i, output, fizzbuzz(i, output));
    }
    return 0;
}
#endif