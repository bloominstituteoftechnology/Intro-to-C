#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
*/
int fizzbuzz(int n)
{
  int fizzbuzzcounter = 0;
  int fizzbuzzstart = 1;

	for (int i = fizzbuzzstart; i <= n; i++) {
	  if ( i % 3 == 0) { 
		  printf("%s\n", "Fizz");
		} else if (i % 5 == 0) {
	 	   printf("%s\n", "Buzz");
		} else if (i % 3 == 0 && i % 5 == 0) {
		  printf("%s\n", "FizzBuzz");
		} else {
		  fizzbuzzcounter++;
		 }
	}
	  return fizzbuzzcounter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
